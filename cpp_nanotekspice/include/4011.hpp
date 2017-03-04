//
// 4011.hpp for 4011.hpp in /home/jeremy/tech2/CPP/cpp_nanotekspice/include
//
// Made by jeremy thiriez
// Login   <jeremy@epitech.net>
//
// Started on  Tue Feb  7 02:42:19 2017 jeremy thiriez
// Last update Sat Mar  4 15:23:49 2017 jeremy thiriez
//

#ifndef Comp4011_HPP_
# define Comp4011_HPP_

#include "AComponent.hpp"

namespace nts
{
  class			Comp4011 : public AComponent
  {
  public:
    Comp4011(std::string);
    virtual ~Comp4011() {};
    nts::Tristate	Nand(nts::Tristate pin1, nts::Tristate pin2);
    nts::Tristate	OutputValue(size_t output);
  };
}

#endif /* ! 4011_HPP_ */
