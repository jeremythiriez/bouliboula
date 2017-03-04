//
// comp4011.cpp for comp4011.cpp in /home/jeremy/tech2/CPP/cpp_nanotekspice/src
//
// Made by jeremy thiriez
// Login   <jeremy@epitech.net>
//
// Started on  Wed Mar  1 16:56:21 2017 jeremy thiriez
// Last update Sat Mar  4 20:27:14 2017 jeremy thiriez
//

#include <string>
#include <iostream>
#include "4011.hpp"
#include "Input.hpp"
#include "Output.hpp"

nts::Comp4011::Comp4011(std::string value) :
  AComponent("4011" + std::string("-") + value)
{
}

nts::Tristate		nts::Comp4011::Nand(nts::Tristate pin1, nts::Tristate pin2)
{
  int			tmp1;
  int			tmp2;

  tmp1 = static_cast<int>(pin1);
  tmp2 = static_cast<int>(pin2);
  if (tmp1 == -1)
    tmp1 = 0;
  if (tmp2 == -1)
    tmp2 = 0;
  return (static_cast<nts::Tristate>(!(tmp1 & tmp2)));
}

nts::Tristate		nts::Comp4011::OutputValue(size_t output)
{
  if (this->_link_inside.find(output) == this->_link_inside.end())
    throw nts::Comp4011::Error("Output does not exist");
  if (!this->_pin[output - 1])
    throw nts::Comp4011::Error("Output does not linked");
  this->_state_pin[output].first = this->Nand(this->InputValue(this->_link_inside[output].first),
					      this->InputValue(this->_link_inside[output].second));
  return (this->_state_pin[output].first);
}
