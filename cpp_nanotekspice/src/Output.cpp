//
// Output.cpp for Output.cpp in /home/jeremy/tech2/CPP/cpp_nanotekspice/src
//
// Made by jeremy thiriez
// Login   <jeremy@epitech.net>
//
// Started on  Thu Mar  2 08:24:28 2017 jeremy thiriez
// Last update Sat Mar  4 19:30:31 2017 jeremy thiriez
//

#include <iostream>
#include <string>
#include "Output.hpp"

nts::Output::Output(std::string name)
{
  this->name = name;
  this->component = NULL;
  this->_state = nts::UNDEFINED;
}

nts::Tristate			nts::Output::Compute(size_t pin_num_this)
{
  this->_state = this->component->Compute(this->link[pin_num_this]);
  return (this->_state);
}

void				nts::Output::SetLink(size_t pin_num_this,
						    nts::IComponent &component,
						    size_t pin_num_target)
{
  pin_num_this = 1;
  if (!this->component)
    {
      if (&component == this)
	throw nts::Output::Error("Can not link this pin to itself");
      this->link[pin_num_this] = pin_num_target;
      this->component = &component;
      component.SetLink(pin_num_target, *this, pin_num_this);
    }
}

void				nts::Output::Dump(void) const
{
  std::string			c;

  c = this->_state + 48;
  if (this->_state == nts::UNDEFINED)
    c = 'U';
  std::cout << this->name << " = " << c << std::endl;
}
