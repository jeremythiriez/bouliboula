//
// comp4071.cpp for comp4071.cpp in /home/jeremy/tech2/CPP/cpp_nanotekspice/src
//
// Made by jeremy thiriez
// Login   <jeremy@epitech.net>
//
// Started on  Wed Mar  1 16:56:21 2017 jeremy thiriez
// Last update Fri Mar  3 10:45:31 2017 jeremy thiriez
//

#include <string>
#include <iostream>
#include "4071.hpp"

nts::Comp4071::Comp4071()
{
  this->name = "4071";
  link_inside[3] = std::make_pair(1, 2);
  link_inside[4] = std::make_pair(5, 6);
  link_inside[10] = std::make_pair(8, 9);
  link_inside[11] = std::make_pair(12, 13);
  for (int i = 0; i < 12; i++)
    this->pin[i] = NULL;
}

nts::Tristate		nts::Comp4071::Or(nts::Tristate pin1, nts::Tristate pin2)
{
  return (static_cast<nts::Tristate>(static_cast<bool>(pin1) ||
				     static_cast<bool>(pin2)));
}

nts::Tristate		nts::Comp4071::Compute(size_t pin_num_this)
{
  if (pin_num_this == 3 || pin_num_this == 4 ||
      pin_num_this == 10 || pin_num_this == 11)
    return (this->OutputValue(pin_num_this));
  else if (pin_num_this >= 1 && pin_num_this <= 13)
    return (this->InputValue(pin_num_this));
  return (nts::UNDEFINED);
}

void			nts::Comp4071::SetLink(size_t pin_num_this,
					       nts::IComponent &component,
					       size_t pin_num_target)
{
  if (!this->pin[pin_num_this - 1])
    {
      this->inter_link[pin_num_this] = pin_num_target;
      this->pin[pin_num_this - 1] = &component;
      component.SetLink(pin_num_target, *this, pin_num_this);
    }
}

void			nts::Comp4071::Dump(void) const
{
  std::cout << this->name << ": " << std::endl;
  for (size_t i = 0; i < 12; i++)
    {
      if (this->pin[i])
	{
	  auto it = this->state_pin.find(i + 1);
	  std::cout << "pin[" << i + 1 << "] = " << it->second
		    << std::endl;
	}
    }
}

nts::Tristate		nts::Comp4071::InputValue(size_t input)
{
  this->state_pin[input] = this->pin[input - 1]->Compute(this->inter_link[input]);
  return (this->state_pin[input]);
}

nts::Tristate		nts::Comp4071::OutputValue(size_t output)
{
  this->state_pin[output] = this->Or(this->InputValue(link_inside[output].first),
				     this->InputValue(link_inside[output].second));
  return (this->state_pin[output]);
}
