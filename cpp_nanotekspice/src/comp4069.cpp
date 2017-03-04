//
// comp4069.cpp for comp4069.cpp in /home/jeremy/tech2/CPP/cpp_nanotekspice/src
//
// Made by jeremy thiriez
// Login   <jeremy@epitech.net>
//
// Started on  Wed Mar  1 16:56:21 2017 jeremy thiriez
// Last update Sat Mar  4 19:44:46 2017 jeremy thiriez
//

#include <string>
#include <iostream>
#include "4069.hpp"
#include "Input.hpp"
#include "Output.hpp"

nts::Comp4069::Comp4069(std::string value)
{
  this->name = "4069" + std::string("-") + value;
  link_inside[2] = 1;
  link_inside[4] = 3;
  link_inside[6] = 5;
  link_inside[8] = 9;
  link_inside[10] = 11;
  link_inside[12] = 13;
  for (int i = 0; i < 13; i++)
    this->pin[i] = NULL;
  for (int i = 0; i < 12; i++)
    this->state_pin[i] = nts::FALSE;
}

nts::Tristate		nts::Comp4069::Not(nts::Tristate pin1)
{
  if (pin1 == nts::UNDEFINED)
    return (nts::UNDEFINED);
  return (static_cast<nts::Tristate>(!static_cast<int>(pin1)));
}

nts::Tristate		nts::Comp4069::Compute(size_t pin_num_this)
{
  if (this->link_inside.find(pin_num_this) != this->link_inside.end())
    return (this->OutputValue(pin_num_this));
  else if (pin_num_this < 1 || pin_num_this > 13)
    throw nts::Comp4069::Error("Pin does not exist");
  return (nts::UNDEFINED);
}

void			nts::Comp4069::SetLink(size_t pin_num_this,
					       nts::IComponent &component,
					       size_t pin_num_target)
{
  bool			val_input = false;

  if (!this->pin[pin_num_this - 1])
    {
      if (&component == this && link_inside[pin_num_this] == pin_num_target)
	throw nts::Comp4069::Error("Can not link Output pin to its input pin");
      if (this->link_inside.find(pin_num_this) != this->link_inside.end() &&
	  dynamic_cast<nts::Input *>(&component))
	throw nts::Comp4069::Error("Can not link Input to Output");
      for (auto &e : this->link_inside)
	if (e.second == pin_num_this)
	  val_input = true;
      if (val_input && dynamic_cast<nts::Output *>(&component))
	throw nts::Comp4069::Error("Can not link Output circuit to input component");
      this->inter_link[pin_num_this] = pin_num_target;
      this->pin[pin_num_this - 1] = &component;
      component.SetLink(pin_num_target, *this, pin_num_this);
    }
}

void			nts::Comp4069::Dump(void) const
{
  std::string		c;

  std::cout << this->name << ": " << std::endl;
  for (size_t i = 0; i < 12; i++)
    {
      if (this->pin[i])
	{
	  auto it = this->state_pin.find(i + 1);
	  c = it->second + 48;
	  if (it->second == nts::UNDEFINED)
	    c = 'U';
	  std::cout << "pin[" << i + 1 << "] = " << c
		    << std::endl;
	}
    }
}

nts::Tristate		nts::Comp4069::InputValue(size_t input)
{
  bool			val_input = false;

  for (auto &e : this->link_inside)
    {
      if (e.second == input)
	val_input = true;
    }
  if (!val_input)
    throw nts::Comp4069::Error("Input does not exist");
  if (!this->pin[input - 1])
    throw nts::Comp4069::Error("Input does not linked");
  this->state_pin[input] = this->pin[input - 1]->Compute(this->inter_link[input]);
  return (this->state_pin[input]);
}

nts::Tristate		nts::Comp4069::OutputValue(size_t output)
{
  if (this->link_inside.find(output) == this->link_inside.end())
    throw nts::Comp4069::Error("Output does not exist");
  if (!this->pin[output - 1])
    throw nts::Comp4069::Error("Output does not linked");
  this->state_pin[output] = this->Not(this->InputValue(link_inside[output]));
  return (this->state_pin[output]);
}
