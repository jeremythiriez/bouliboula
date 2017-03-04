//
// Input.cpp for Input.cpp in /home/jeremy/tech2/CPP/cpp_nanotekspice/src
//
// Made by jeremy thiriez
// Login   <jeremy@epitech.net>
//
// Started on  Thu Mar  2 08:24:28 2017 jeremy thiriez
// Last update Sat Mar  4 19:26:48 2017 jeremy thiriez
//

#include <string>
#include <iostream>
#include "Input.hpp"

nts::Input::Input(std::string name)
{
  this->name = name;
  this->component = NULL;
  this->_state = nts::UNDEFINED;
}

nts::Tristate			nts::Input::Compute(size_t pin_num_this)
{
  (void)pin_num_this;
  return (this->_state);
}

void				nts::Input::SetLink(size_t pin_num_this,
						    nts::IComponent &component,
						    size_t pin_num_target)
{
  pin_num_this = 1;
  if (!this->component)
    {
      this->component = &component;
      component.SetLink(pin_num_target, *this, pin_num_this);
    }
}

void				nts::Input::Dump(void) const
{
  std::string			c;

  c = this->_state + 48;
  if (this->_state == nts::UNDEFINED)
    c = "U";
  std::cout << this->name << " = " << c << std::endl;
}

void				nts::Input::setValue(nts::Tristate val)
{
  this->_state = val;
}
