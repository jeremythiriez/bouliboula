//
// comp4030.cpp for comp4030.cpp in /home/jeremy/tech2/CPP/cpp_nanotekspice/src
//
// Made by jeremy thiriez
// Login   <jeremy@epitech.net>
//
// Started on  Wed Mar  1 16:56:21 2017 jeremy thiriez
// Last update Sat Mar  4 20:27:38 2017 jeremy thiriez
//

#include <string>
#include <iostream>
#include "4030.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include "AComponent.hpp"

nts::Comp4030::Comp4030(std::string value) :
  AComponent("4030" + std::string("-") + value)
{
}

nts::Tristate		nts::Comp4030::Xor(nts::Tristate pin1, nts::Tristate pin2)
{
  int			tmp1;
  int			tmp2;

  tmp1 = static_cast<int>(pin1);
  tmp2 = static_cast<int>(pin2);
  if (tmp1 == -1)
    tmp1 = 0;
  if (tmp2 == -1)
    tmp2 = 0;
  return (static_cast<nts::Tristate>(tmp1 ^ tmp2));
}

nts::Tristate		nts::Comp4030::OutputValue(size_t output)
{
  if (this->_link_inside.find(output) == this->_link_inside.end())
    throw nts::Comp4030::Error("Output does not exist");
  if (!this->_pin[output - 1])
    throw nts::Comp4030::Error("Output does not linked");
  this->_state_pin[output].first = this->Xor(this->InputValue(this->_link_inside[output].first),
				     this->InputValue(this->_link_inside[output].second));
  return (this->_state_pin[output].first);
}
