//
// Output.cpp for Output.cpp in /home/jeremy/tech2/CPP/cpp_nanotekspice/src
//
// Made by jeremy thiriez
// Login   <jeremy@epitech.net>
//
// Started on  Thu Mar  2 08:24:28 2017 jeremy thiriez
// Last update Fri Mar  3 10:52:21 2017 jeremy thiriez
//

#include <iostream>
#include <string>
#include "Output.hpp"

nts::Output::Output(std::string name)
{
  this->name = name;
  this->component = NULL;
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
      this->link[pin_num_this] = pin_num_target;
      this->component = &component;
      component.SetLink(pin_num_target, *this, pin_num_this);
    }
}

void				nts::Output::Dump(void) const
{
  std::cout << this->name << " = " << this->_state << std::endl;
}
