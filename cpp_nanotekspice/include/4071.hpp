//
// 4071.hpp for 4071.hpp in /home/jeremy/tech2/CPP/cpp_nanotekspice/include
//
// Made by jeremy thiriez
// Login   <jeremy@epitech.net>
//
// Started on  Tue Feb  7 02:42:19 2017 jeremy thiriez
// Last update Sat Mar  4 16:04:58 2017 jeremy thiriez
//

#ifndef Comp4071_HPP_
# define Comp4071_HPP_

#include "AComponent.hpp"

namespace nts
{
  class			Comp4071 : public AComponent
  {
  public:
    Comp4071(std::string const& name);
    virtual ~Comp4071() {};
    nts::Tristate	Or(nts::Tristate pin1, nts::Tristate pin2);
    nts::Tristate	OutputValue(size_t output);
  };
}

#endif /* ! 4071_HPP_ */
