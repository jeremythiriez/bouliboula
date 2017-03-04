//
// circuit.cpp for circuit.cpp in /home/jeremy/tech2/CPP/cpp_nanotekspice/src
//
// Made by jeremy thiriez
// Login   <jeremy@epitech.net>
//
// Started on  Tue Feb  7 10:16:07 2017 jeremy thiriez
// Last update Sun Mar  5 23:05:51 2017 etienne.dewever@epitech.eu
//

#include <string>
#include <iostream>
#include "AComponent.hpp"
#include "Circuit.hpp"
#include "Input.hpp"
#include "4071.hpp"
#include "Output.hpp"

nts::Circuit::Circuit(char **av)
  : _fileName(av[1])
{
  std::fstream		file(av[1], std::ifstream::in);
  std::string		line;
  t_ast_node		*root;

  this->_parser = new Parser(*this);
  while (getline(file, line))
    this->_parser->feed(line);
  root = _parser->createTree();
  this->_parser->parseTree(*root);
    _parser->feed(line);
    this->clock = false;
  (void)root;
}

nts::Tristate			nts::Circuit::Compute(size_t pin_num_this)
{
  (void)pin_num_this;
  this->clock = !this->clock;
  for (auto &e : this->_output)
    e.second->Compute();
  return (nts::TRUE);
}

void				nts::Circuit::SetLink(size_t pin_num_this,
						      nts::IComponent &component,
						      size_t pin_num_target)
{
  (void)pin_num_this;
  (void)component;
  (void)pin_num_target;
}

void				nts::Circuit::Dump(void) const
{
  std::cout << "Circuit:" << std::endl;
  for (auto &e : this->_input)
    e.second->Dump();
  for (auto &e : this->_output)
    e.second->Dump();
}

void				nts::Circuit::DumpOutput(void) const
{
  for (auto &e : this->_output)
    e.second->Dump();
}

nts::Parser				*nts::Circuit::getParser() const
{
  return _parser;
}

std::unordered_map<std::string, nts::Input*>	nts::Circuit::getInput() const
{
  return this->_input;
}

std::unordered_map<std::string, nts::Output*>	nts::Circuit::getOutput() const
{
  return this->_output;
}

std::unordered_map<std::string, nts::IComponent*>	nts::Circuit::getComponent() const
{
  return this->_components;
}

nts::Relevant const				&nts::Circuit::getFactory() const
{
  return (this->_factory);
}

void					nts::Circuit::addElement(std::string const &type,
								 std::string const &name)
{
  IComponent				*element;
  AComponent				*cast;

  element = this->_factory.createComponent(type, name);
  if ((cast = dynamic_cast<nts::AComponent*>(element)) != NULL)
    cast->clock = &this->clock;
  if (type == "input")
    this->_input[name] = static_cast<Input *>(element);
  else if (type == "output")
    this->_output[name] = static_cast<Output *>(element);
  else
    this->_components[name] = element;
 }

nts::IComponent				*nts::Circuit::searchComponent(std::string const &name)
{
  if (this->getInput().find(name) != this->getInput().end())
    return this->getInput()[name];
  if (this->getOutput().find(name) != this->getOutput().end())
    return this->getOutput()[name];
  return this->getComponent()[name];
}
