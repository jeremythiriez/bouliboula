//
// AComponent.cpp for AComponent in /mnt/dump/deweve_e/tek2/nano/cpp_nanotekspice/src
//
// Made by etienne.dewever@epitech.eu
// Login   <deweve_e@epitech.eu>
//
// Started on  Sun Mar  5 16:28:25 2017 etienne.dewever@epitech.eu

#include <iostream>
#include "AComponent.hpp"
#include "Input.hpp"
#include "Output.hpp"

nts::AComponent::AComponent(std::string const &name) :
  _state_pin(14, std::make_pair(nts::UNDEFINED, false))
{
  _name = name;
  this->clock = new bool(false);
  this->_link_inside[3] = std::make_pair(1, 2);
  this->_link_inside[4] = std::make_pair(5, 6);
  this->_link_inside[10] = std::make_pair(8, 9);
  this->_link_inside[11] = std::make_pair(12, 13);
  for (int i = 0; i < 13; i++)
    this->_pin[i] = NULL;
}

void		nts::AComponent::SetLink(size_t pin_num_this, nts::IComponent &component,
					 size_t pin_num_target)
{
  bool		val_input = false;

  if (!this->_pin[pin_num_this - 1])
    {
      if (this->_link_inside.find(pin_num_this) != this->_link_inside.end() &&
	  dynamic_cast<nts::Input *>(&component))
	throw nts::AComponent::Error("Can not link Input to Output");
      for (auto &e : this->_link_inside)
	if (e.second.first == pin_num_this || e.second.second == pin_num_this)
	  val_input = true;
      if (val_input && dynamic_cast<nts::Output *>(&component))
	throw nts::AComponent::Error("Can not link Output circuit to input component");
      this->_inter_link[pin_num_this] = pin_num_target;
      this->_pin[pin_num_this - 1] = &component;
      component.SetLink(pin_num_target, *this, pin_num_this);
    }
}

nts::Tristate		nts::AComponent::Compute(size_t pin_num_this)
{
  if (this->_link_inside.find(pin_num_this) != this->_link_inside.end() &&
      this->_state_pin[pin_num_this].second == *this->clock)
    {
      this->_state_pin[pin_num_this].second = !this->_state_pin[pin_num_this].second;
      return (this->OutputValue(pin_num_this));
    }
  else if (pin_num_this < 1 || pin_num_this > 13)
    throw nts::AComponent::Error("Pin does not exist");
  return (this->_state_pin[pin_num_this].first);
}

void		nts::AComponent::Dump(void) const
{
  char		c;

  std::cout << this->_name << ": " << std::endl;
  for (size_t i = 0; i < 13; i++)
    {
      if (this->_pin[i])
	{
	  c = this->_state_pin[i + 1].first + 48;
	  if (this->_state_pin[i + 1].first == nts::UNDEFINED)
	    c = 'U';
	  std::cout << "pin[" << i + 1 << "] = " << c << std::endl;
	}
    }
}

nts::Tristate		nts::AComponent::InputValue(size_t input)
{
  bool			val_input = false;

  for (auto &e : this->_link_inside)
    {
      if (e.second.first == input || e.second.second == input)
	val_input = true;
    }
  if (!val_input)
    throw nts::AComponent::Error("Input does not exist");
  if (!this->_pin[input - 1])
    throw nts::AComponent::Error("Input does not linked");
  this->_state_pin[input].first = this->_pin[input - 1]->Compute(this->_inter_link[input]);
  return (this->_state_pin[input].first);
}
