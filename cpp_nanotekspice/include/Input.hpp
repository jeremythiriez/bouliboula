//
// Input.hpp for Input.hpp in /home/jeremy/tech2/CPP/cpp_nanotekspice/include
//
// Made by jeremy thiriez
// Login   <jeremy@epitech.net>
//
// Started on  Tue Feb  7 12:32:01 2017 jeremy thiriez
// Last update Fri Mar  3 10:53:09 2017 jeremy thiriez
//

#ifndef INPUT_HPP_
# define INPUT_HPP_

#include "IComponent.hpp"

namespace nts
{
  class			Input : public IComponent
  {
  private:
    std::string			name;
    nts::IComponent		*component;
    nts::Tristate		_state;
  public:
    Input(std::string);
    ~Input() {};
    nts::Tristate		Compute(size_t pin_num_this = 1);
    void			SetLink(size_t pin_num_this,
					nts::IComponent &component,
					size_t pin_num_tager);
    void			Dump(void) const;
    void			setValue(nts::Tristate);
  };
}

#endif /* !INPUT_HPP_ */
