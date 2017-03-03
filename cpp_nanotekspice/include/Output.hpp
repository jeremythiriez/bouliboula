//
// Output.hpp for Output.hpp in /home/jeremy/tech2/CPP/cpp_nanotekspice/include
//
// Made by jeremy thiriez
// Login   <jeremy@epitech.net>
//
// Started on  Tue Feb  7 12:32:01 2017 jeremy thiriez
// Last update Fri Mar  3 10:53:23 2017 jeremy thiriez
//

#ifndef OUTPUT_HPP_
# define OUTPUT_HPP_

#include <unordered_map>
#include "IComponent.hpp"

namespace nts
{
  class			Output : public IComponent
  {
  private:
    std::string			name;
    nts::IComponent		*component;
    std::unordered_map<size_t, size_t>		link;
    nts::Tristate		_state;
  public:
    Output(std::string);
    ~Output() {};
    nts::Tristate		Compute(size_t pin_num_this = 1);
    void			SetLink(size_t pin_num_this,
					nts::IComponent &component,
					size_t pin_num_tager);
    void			Dump(void) const;
  };
}

#endif /* !INPUT_HPP_ */
