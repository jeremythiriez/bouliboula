//
// circuit.cpp for circuit.cpp in /home/jeremy/tech2/CPP/cpp_nanotekspice/src
//
// Made by jeremy thiriez
// Login   <jeremy@epitech.net>
//
// Started on  Tue Feb  7 10:16:07 2017 jeremy thiriez
// Last update Fri Mar  3 10:55:46 2017 jeremy thiriez
//

#include <iostream>
#include "IComponent.hpp"
#include "Circuit.hpp"
#include "Input.hpp"
#include "4071.hpp"
#include "Output.hpp"

nts::Circuit::Circuit(char **av)
  : _fileName(av[1])
{
  std::fstream file(av[1], std::ifstream::in);
  std::string line;
  t_ast_node		*root;

  _parser = new Parser();
  while (getline(file, line))
    _parser->feed(line);
  // root = _parser->createTree();
  // this->_parser->parseTree(*root);
  (void)root;

  _input["a"] = new Input("a");
  _input["b"] = new Input("b");
  _output["c"] = new Output("c");
  _component["4071"] = new Comp4071;

  _component["4071"]->SetLink(1, *_input["a"], 1);
  _component["4071"]->SetLink(2, *_input["b"], 1);
  _component["4071"]->SetLink(3, *_output["c"], 1);

  _input["a"]->setValue(nts::TRUE);
  _input["b"]->setValue(nts::TRUE);

}

nts::Tristate			nts::Circuit::Compute(size_t pin_num_this)
{
  (void)pin_num_this;
  for (auto e : this->_output)
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
  for (auto e : this->_input)
    e.second->Dump();
  for (auto e : this->_output)
    e.second->Dump();
}

void				nts::Circuit::DumpOutput(void) const
{
  for (auto e : this->_output)
    std::cout << e.first << " = " << e.second->Compute() << std::endl;
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
  return this->_component;
}
