//
// parser.cpp for parser.cpp in /home/jeremy/tech2/CPP/cpp_nanotekspice/src
//
// Made by jeremy thiriez
// Login   <jeremy@epitech.net>
//
// Started on  Mon Feb  6 19:35:20 2017 jeremy thiriez
// Last update Wed Mar  1 14:10:30 2017 jeremy thiriez
//

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "Parser.hpp"

nts::Parser::Parser()
{
  this->_mode = nts::Parser::UNDEFINED;
  this->_feed.resize(2);
  this->_componentName = {
    "input",
    "output",
    "4001",
    "4008",
    "4011",
    "4013",
    "4017",
    "4030",
    "4040",
    "4069",
    "4071",
    "4081",
    "4094",
    "4514",
    "4801",
    "2716"
  };
}

nts::Parser::~Parser()
{
}

// nts::Parser::Parser(Parser const& other)
// {
//   this->_file = other._file;
// }

// nts::Parser const&		nts::Parser::operator=(Parser const& other)
// {
//   (void)other;
//   return (*this);
// }

void				nts::Parser::checkComponent(std::string const& line)
{
  std::stringstream		word;
  std::string			cpy = line;

  word << cpy;
  word >> cpy;
  if (std::find(_componentName.begin(), _componentName.end(), cpy) == _componentName.end())
    throw ("Component Unknow !");
  this->_feed[this->_mode].push_back(line);
  word >> cpy;
  this->_chipsetName.push_back(cpy);
}

void				nts::Parser::checkLink(std::string const& line)
{
  std::stringstream		word;
  std::string			cpy = line;
  size_t			pos;

  for (int i = 0; i < 2; i++)
    {
      word << cpy;
      word >> cpy;
      if ((pos = cpy.find(":")) == cpy.npos)
	throw ("...");
      cpy = cpy.substr(0, pos);
      if (std::find(_chipsetName.begin(), _chipsetName.end(), cpy) == _chipsetName.end())
	throw ("...");
    }
  this->_feed[this->_mode].push_back(line);
}

void				nts::Parser::feed(std::string const& other)
{
  if (other.find('#') != other.npos || other == "")
    return;
  if (other == ".chipsets:")
    {
      this->_mode = nts::Parser::CHIPSET;
      return ;
    }
  if (other == ".links:")
    {
      this->_mode = nts::Parser::LINK;
      return ;
    }
  if (this->_mode == nts::Parser::UNDEFINED)
    {
      std::cerr << "Mode Undefined" << std::endl;
      return ;
    }
  if (this->_mode == nts::Parser::CHIPSET)
    this->checkComponent(other);
  if (this->_mode == nts::Parser::LINK)
    this->checkLink(other);
}

void				nts::Parser::parseTree(t_ast_node& root)
{
  std::cout << root.value << std::endl;
  for (auto &e : *root.children)
    {
      std::cout << e->value << std::endl;
    }
}

nts::t_ast_node			*nts::Parser::createTree()
{
  nts::t_ast_node		*left = new nts::t_ast_node(NULL);
  nts::t_ast_node		*right = new nts::t_ast_node(NULL);
  nts::t_ast_node		*root = new nts::t_ast_node(NULL);

  root->type = nts::ASTNodeType::NEWLINE;
  root->value = "\n";
  root->children = new std::vector<nts::s_ast_node *>();
  left->type = nts::ASTNodeType::SECTION;
  left->value = ".links:";
  right->type = nts::ASTNodeType::SECTION;
  right->value = ".chipsets:";
  root->children->push_back(left);
  root->children->push_back(right);

  return (root);
}

std::vector<std::vector<std::string>>	nts::Parser::getFeed() const
{
  return _feed;
}
