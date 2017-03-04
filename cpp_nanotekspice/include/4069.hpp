//
// 4069.hpp for 4069.hpp in /home/jeremy/tech2/CPP/cpp_nanotekspice/include
//
// Made by jeremy thiriez
// Login   <jeremy@epitech.net>
//
// Started on  Tue Feb  7 02:42:19 2017 jeremy thiriez
// Last update Sun Mar  5 23:06:25 2017 etienne.dewever@epitech.eu
//

#ifndef Comp4069_HPP_
# define Comp4069_HPP_

# include <unordered_map>
# include <functional>
# include <vector>
# include "IComponent.hpp"

namespace nts
{
  class			Comp4069 : public IComponent
  {
  public:
    class		Error : public std::exception
    {
    private:
      std::string	_msg;
    public:
      Error(std::string const &other) {this->_msg = other;};
      ~Error() throw() {};
      char const		*what() const throw()
      {
	return _msg.c_str();
      }
    };
    Comp4069(std::string);
    virtual ~Comp4069() {};
    nts::Tristate	Compute(size_t pin_num_this = 1);
    void		SetLink(size_t pin_num_this,
				nts::IComponent &component,
				size_t pin_num_target);
    void		Dump(void) const;
    nts::Tristate	Not(nts::Tristate pin1);
    nts::Tristate	InputValue(size_t input);
    nts::Tristate	OutputValue(size_t output);
  private:
    std::string							name;
    IComponent							*pin[13];
    std::unordered_map<size_t, size_t>				inter_link;
    std::unordered_map<size_t, size_t>				link_inside;
    std::unordered_map<size_t, nts::Tristate>			state_pin;
  };
}

#endif /* ! 4069_HPP_ */
