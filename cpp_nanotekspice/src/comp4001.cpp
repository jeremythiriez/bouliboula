//
// comp4001.cpp for comp4001.cpp in /home/jeremy/tech2/CPP/cpp_nanotekspice/src
//
// Made by jeremy thiriez
// Login   <jeremy@epitech.net>
//
// Started on  Wed Mar  1 16:56:21 2017 jeremy thiriez
// Last update Sat Mar  4 20:26:50 2017 jeremy thiriez
//

#include <string>
#include <iostream>
#include "4001.hpp"
#include "Input.hpp"
#include "Output.hpp"

nts::Comp4001::Comp4001(std::string value) :
  AComponent("4001" + std::string("-") + value)
{
}

nts::Tristate		nts::Comp4001::Nor(nts::Tristate pin1, nts::Tristate pin2)
{
  int			tmp1;
  int			tmp2;

  tmp1 = static_cast<int>(pin1);
  tmp2 = static_cast<int>(pin2);
  if (tmp1 == -1)
    tmp1 = 0;
  if (tmp2 == -1)
    tmp2 = 0;
  return (static_cast<nts::Tristate>(!(tmp1 | tmp2)));
}

nts::Tristate		nts::Comp4001::OutputValue(size_t output)
{
  if (this->_link_inside.find(output) == this->_link_inside.end())
    throw nts::Comp4001::Error("Output does not exist");
  if (!this->_pin[output - 1])
    throw nts::Comp4001::Error("Output does not linked");
  this->_state_pin[output].first = this->Nor(this->InputValue(this->_link_inside[output].first),
				     this->InputValue(this->_link_inside[output].second));
  return (this->_state_pin[output].first);
}
