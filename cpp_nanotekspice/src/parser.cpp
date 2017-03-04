//
// parser.cpp for parser.cpp in /home/jeremy/tech2/CPP/cpp_nanotekspice/src
//
// Made by jeremy thiriez
// Login   <jeremy@epitech.net>
//
// Started on  Mon Feb  6 19:35:20 2017 jeremy thiriez
// Last update Sun Mar  5 22:54:31 2017 etienne.dewever@epitech.eu
//

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <regex>
#include "Parser.hpp"
#include "Relevant.hpp"

nts::Parser::Parser(nts::Circuit &parent) :
  _parent(parent)
{
  this->_mode = nts::Parser::UNDEFINED;
  this->_feed.resize(2);
}

nts::Parser::~Parser()
{
}

nts::Circuit const			&nts::Parser::getParent() const
{
  return (this->_parent);
}

void					nts::Parser::checkComponent(std::string const& line)
{
  std::regex					stringFormat("^(\\w+|\\s+)\\s+(\\w+|\\s+)$");
  std::smatch					base_match;
  std::unordered_map<std::string, func> const 	factory = this->_parent.getFactory().getTable();

  if (!std::regex_match(line, base_match, stringFormat) || base_match.size() != 3)
    throw nts::Parser::Error("The circuit file includes one or several lexical errors or syntactic errors.");
  if (factory.find(base_match[1]) == factory.end())
    throw nts::Parser::Error("A component type is unknown");
  if (std::find(this->_chipsetName.begin(), this->_chipsetName.end(),
		base_match[2]) != this->_chipsetName.end())
    throw nts::Parser::Error("Several components share the same name");
  this->_chipsetName.push_back(base_match[2]);
  this->_feed[nts::Parser::CHIPSET].push_back(base_match[0]);
}

void					nts::Parser::checkLink(std::string const& line)
{
  std::regex				string_link("(\\w+|\\d+)+:\\d+\\s+(\\w+|\\d+)+:\\d+");
  std::smatch				base_match;

  if (!std::regex_match(line, base_match, string_link) || base_match.size() != 3)
    throw nts::Parser::Error("The circuit file includes one or several lexical errors or syntactic errors.");
  if (std::find(this->_chipsetName.begin(), this->_chipsetName.end(),
		base_match[1]) == this->_chipsetName.end()
      || std::find(this->_chipsetName.begin(), this->_chipsetName.end(),
		   base_match[2]) == this->_chipsetName.end())
    throw nts::Parser::Error("A component name is unknown");
  this->_feed[nts::Parser::LINK].push_back(line);
}

void				nts::Parser::feed(std::string const& other)
{
  static std::unordered_map<std::string, nts::Parser::e_type>	mode = {
    {".chipsets:", nts::Parser::CHIPSET},
    {".links:", nts::Parser::LINK}
  };

  if (other.find('#') != other.npos || other == "")
    return;
  if (mode.find(other) != mode.end())
    {
      this->_mode = mode[other];
      return;
    }
  if (this->_mode == nts::Parser::UNDEFINED)
    throw nts::Parser::Error("The circuit file includes one or several lexical errors or syntactic errors.");
  if (this->_mode == nts::Parser::CHIPSET)
    this->checkComponent(other);
  if (this->_mode == nts::Parser::LINK)
    this->checkLink(other);
}

nts::t_ast_node		*nts::Parser::create(std::string const ref, nts::ASTNodeType type,
					     nts::t_ast_node *child)
{
  t_ast_node			*tmp = new nts::t_ast_node(NULL);

  tmp->value = ref;
  tmp->type = type;
  if (child)
    {
      tmp->children = new std::vector<t_ast_node*>;
      tmp->children->push_back(child);
    }
  return tmp;
}

void				set_node_chipset(nts::t_ast_node *tree,
						 std::vector<std::string> list)
{
  std::string			type;

  for (auto &it : list)
    tree->children->push_back(nts::Parser::create(it,
						  nts::ASTNodeType::COMPONENT,
						  NULL));
}

void				set_node_link(nts::t_ast_node *tree,
					      std::vector<std::string> list)
{
  std::regex			string_link("^(\\w+:\\d+)\\s+(\\w+:\\d+)$");
  std::smatch			base_match;
  nts::t_ast_node		*link;
  nts::t_ast_node		*link_end;

  for (auto &it : list)
    {
      if (std::regex_match(it, base_match, string_link) && base_match.size() == 3)
	{
	  link_end = nts::Parser::create(base_match[2], nts::ASTNodeType::LINK_END, NULL);
	  link = nts::Parser::create(base_match[1], nts::ASTNodeType::LINK, link_end);
	  tree->children->push_back(link);
	}
    }
}

void				nts::Parser::setLink(t_ast_node *links)
{
  std::regex			strig_format("^(\\d+|\\w+)+:(\\d+)$");
  std::smatch			base_match;
  std::pair<std::string, int>	link_begin;
  std::pair<std::string, int>	link_end;
  IComponent			*second_component;

  if (!links->children or links->children->size() == 0)
    throw nts::Parser::Error("No links section");
  for (auto &it : *links->children)
    {
      std::regex_match(it->value, base_match, strig_format);
      link_begin.first = base_match[1];
      link_begin.second = std::atoi(base_match[2].str().c_str());
      std::regex_match((*it->children)[0]->value, base_match, strig_format);
      link_end.first = base_match[1];
      link_end.second = std::atoi(base_match[2].str().c_str());
      second_component = this->_parent.searchComponent(link_end.first);
      this->_parent.searchComponent(link_begin.first)->SetLink(link_begin.second, *second_component,
							       link_end.second);
    }
}

void			nts::Parser::createChipset(t_ast_node *chipsets)
{
  std::regex		string_format("^(\\w+|\\d+)\\s+(\\w+|\\d+)+$");
  std::smatch		base_match;

  if (!chipsets->children or chipsets->children->size() == 0)
    throw nts::Parser::Error("No chipset section");
  for (auto &it: *chipsets->children)
    {
      if (std::regex_match(it->value, base_match, string_format))
  	this->_parent.addElement(base_match[1], base_match[2]);
    }
}

void			nts::Parser::parseTree(t_ast_node &root)
{

  this->createChipset((*root.children)[nts::Parser::CHIPSET]);
  this->setLink((*root.children)[nts::Parser::LINK]);
}

nts::t_ast_node			*nts::Parser::createTree()
{
  nts::t_ast_node		*left = new nts::t_ast_node(new std::vector<nts::t_ast_node*>);
  nts::t_ast_node		*right = new nts::t_ast_node(new std::vector<nts::t_ast_node*>);
  nts::t_ast_node		*root = new nts::t_ast_node(new std::vector<nts::t_ast_node *>);

  root->type = nts::ASTNodeType::NEWLINE;
  root->value = "\n";
  left->type = nts::ASTNodeType::SECTION;
  left->value = ".links:";
  right->type = nts::ASTNodeType::SECTION;
  right->value = ".chipsets:";
  root->children->push_back(right);
  root->children->push_back(left);
  set_node_link((*root->children)[static_cast<int>(nts::Parser::LINK)],
		this->_feed[static_cast<int>(nts::Parser::LINK)]);
  set_node_chipset((*root->children)[static_cast<int>(nts::Parser::CHIPSET)],
		   this->_feed[static_cast<int>(nts::Parser::CHIPSET)]);
  return (root);
}

std::vector<std::vector<std::string>> const &	nts::Parser::getFeed() const
{
  return _feed;
}
