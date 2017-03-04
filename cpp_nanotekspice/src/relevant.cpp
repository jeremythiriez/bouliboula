//w
// relevant.cpp for relevant.cpp in /home/jeremy/tech2/CPP/cpp_nanotekspice/src
//
// Made by jeremy thiriez
// Login   <jeremy@epitech.net>
//
// Started on  Tue Feb  7 19:10:24 2017 jeremy thiriez
// Last update Sat Mar  4 18:42:47 2017 jeremy thiriez
//

#include "4071.hpp"
#include "4011.hpp"
#include "4081.hpp"
#include "4001.hpp"
#include "4069.hpp"
#include "4030.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include "Relevant.hpp"

nts::Relevant::Relevant()
{
  this->_tabFunc["4071"] = &nts::Relevant::create4071;
  this->_tabFunc["4011"] = &nts::Relevant::create4011;
  this->_tabFunc["4081"] = &nts::Relevant::create4081;
  this->_tabFunc["4001"] = &nts::Relevant::create4001;
  this->_tabFunc["4069"] = &nts::Relevant::create4069;
  this->_tabFunc["4030"] = &nts::Relevant::create4030;
  this->_tabFunc["input"] = &nts::Relevant::createInput;
  this->_tabFunc["output"] = &nts::Relevant::createOutput;
}

nts::IComponent		*nts::Relevant::createComponent(const std::string &type,
							const std::string &value)
{
  return (this->*_tabFunc[type])(value);
}

nts::IComponent		*nts::Relevant::create4071(const std::string &value) const
{
  return (new Comp4071(value));
}

nts::IComponent		*nts::Relevant::create4011(const std::string &value) const
{
  return (new Comp4011(value));
}

nts::IComponent		*nts::Relevant::create4081(const std::string &value) const
{
  return (new Comp4081(value));
}

nts::IComponent		*nts::Relevant::create4001(const std::string &value) const
{
  return (new Comp4001(value));
}

nts::IComponent		*nts::Relevant::create4069(const std::string &value) const
{
  return (new Comp4069(value));
}

nts::IComponent		*nts::Relevant::create4030(const std::string &value) const
{
  return (new Comp4030(value));
}

nts::IComponent		*nts::Relevant::createInput(const std::string &value) const
{
  return (new Input(value));
}

nts::IComponent		*nts::Relevant::createOutput(const std::string &value) const
{
  return (new Output(value));
}

std::unordered_map<std::string, nts::func> const	&nts::Relevant::getTable() const
{
  return (this->_tabFunc);
}
