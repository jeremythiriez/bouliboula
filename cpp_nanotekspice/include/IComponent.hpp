//
// IComponent.hpp for IComponent.hpp in /home/jeremy/tech2/CPP/cpp_nanotekspice
//
// Made by jeremy thiriez
// Login   <jeremy@epitech.net>
//
// Started on  Mon Feb  6 18:56:28 2017 jeremy thiriez
// Last update Tue Feb  7 12:02:51 2017 jeremy thiriez
//

#ifndef __ICOMPONENT_HPP__
# define __ICOMPONENT_HPP__

#include <string>

namespace nts
{
  enum Tristate
    {
      UNDEFINED = (-true),
      TRUE = true,
      FALSE = false
    };

  class				IComponent
  {
  public:
    virtual nts::Tristate	Compute(size_t pin_num_this = 1) = 0;
    virtual void		SetLink(size_t pin_num_this,
					nts::IComponent &component,
					size_t pin_num_target) = 0;
    virtual void		Dump(void) const = 0;
    virtual ~IComponent() {};
  };
}

#endif /* !__ICOMPONENT_HPP__ */
