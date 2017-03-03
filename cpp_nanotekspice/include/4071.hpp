//
// 4071.hpp for 4071.hpp in /home/jeremy/tech2/CPP/cpp_nanotekspice/include
//
// Made by jeremy thiriez
// Login   <jeremy@epitech.net>
//
// Started on  Tue Feb  7 02:42:19 2017 jeremy thiriez
// Last update Fri Mar  3 09:56:05 2017 jeremy thiriez
//

#ifndef Comp4071_HPP_
# define Comp4071_HPP_

#include <unordered_map>
#include <functional>
#include <vector>
#include "IComponent.hpp"

namespace nts
{
  class			Comp4071 : public IComponent
  {
  private:
    std::string							name;
    IComponent							*pin[12];
    std::unordered_map<size_t, size_t>				inter_link;
    std::unordered_map<size_t, std::pair<size_t, size_t>>	link_inside;
    std::unordered_map<size_t, nts::Tristate>			state_pin;
  public:
    Comp4071();
    virtual ~Comp4071() {};
    nts::Tristate	Compute(size_t pin_num_this = 1);
    void		SetLink(size_t pin_num_this,
				nts::IComponent &component,
				size_t pin_num_target);
    void		Dump(void) const;
    nts::Tristate	Or(nts::Tristate pin1, nts::Tristate pin2);
    nts::Tristate	InputValue(size_t input);
    nts::Tristate	OutputValue(size_t output);
  };
}

#endif /* ! 4071_HPP_ */
