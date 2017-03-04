//
// 4001.hpp for 4001.hpp in /home/jeremy/tech2/CPP/cpp_nanotekspice/include
//
// Made by jeremy thiriez
// Login   <jeremy@epitech.net>
//
// Started on  Tue Feb  7 02:42:19 2017 jeremy thiriez
// Last update Sat Mar  4 15:23:22 2017 jeremy thiriez
//

#ifndef Comp4001_HPP_
# define Comp4001_HPP_

#include "AComponent.hpp"

namespace nts
{
  class			Comp4001 : public AComponent
  {
  public:
    Comp4001(std::string);
    virtual ~Comp4001() {};
    nts::Tristate	Nor(nts::Tristate pin1, nts::Tristate pin2);
    nts::Tristate	OutputValue(size_t output);
  };
}

#endif /* ! 4001_HPP_ */
