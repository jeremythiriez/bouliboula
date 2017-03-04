//
// AComponent.hpp for nts in /mnt/dump/deweve_e/tek2/nano/cpp_nanotekspice/include
//
// Made by etienne.dewever@epitech.eu
// Login   <deweve_e@epitech.eu>
//
// Started on  Sun Mar  5 16:11:48 2017 etienne.dewever@epitech.eu
// Last update Sun Mar  5 22:16:19 2017 etienne.dewever@epitech.eu
//

#ifndef ACOMPONENT_HPP_
# define ACOMPONENT_HPP_

#include <memory>
#include <string>
#include <exception>
#include <unordered_map>
#include <vector>
#include "IComponent.hpp"

namespace nts
{
  class		AComponent : public IComponent
  {
  protected:
    std::string							_name;
    IComponent							*_pin[13];
    std::unordered_map<size_t, size_t>				_inter_link;
    std::vector<std::pair<nts::Tristate, bool>>			_state_pin;
    std::unordered_map<size_t, std::pair<size_t, size_t>>	_link_inside;
  public:
    class	Error : public std::exception
    {
    private:
      std::string	_msg;
    public:
      Error(std::string const &msg) { _msg = msg;};
      ~Error() throw() {};
      char const	*what() const throw() { return _msg.c_str(); }
    };

  public:
    AComponent(std::string const &name);
    virtual ~AComponent() {};
    virtual nts::Tristate		Compute(size_t pin_num_this = 1);
    virtual void			SetLink(size_t pin_num_this,
						nts::IComponent &component,
						size_t pin_num_target);
    virtual void			Dump(void) const;
    virtual nts::Tristate		InputValue(size_t input);
    virtual nts::Tristate		OutputValue(size_t output) = 0;
    bool				*clock;
  };
}

#endif /* ACOMPONENT_HPP_ */
