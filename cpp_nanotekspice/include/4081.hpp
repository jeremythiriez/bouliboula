  //
// 4081.hpp for 4081.hpp in /home/jeremy/tech2/CPP/cpp_nanotekspice/include
//
// Made by jeremy thiriez
// Login   <jeremy@epitech.net>
//
// Started on  Tue Feb  7 02:42:19 2017 jeremy thiriez
// Last update Sat Mar  4 15:22:39 2017 jeremy thiriez
//

#ifndef Comp4081_HPP_
# define Comp4081_HPP_

#include "AComponent.hpp"

namespace nts
{
  class			Comp4081 : public AComponent
  {
  public:
    Comp4081(std::string);
    virtual ~Comp4081() {};
    nts::Tristate	And(nts::Tristate pin1, nts::Tristate pin2);
    nts::Tristate	OutputValue(size_t output);
  };
}

#endif /* ! 4081_HPP_ */
