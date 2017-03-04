//
// Relevant.hpp for Relevent.hpp in /home/jeremy/tech2/CPP/cpp_nanotekspice/include
//
// Made by jeremy thiriez
// Login   <jeremy@epitech.net>
//
// Started on  Tue Feb  7 18:54:57 2017 jeremy thiriez
// Last update Sun Mar  5 22:50:53 2017 etienne.dewever@epitech.eu
//

#ifndef RELEVANT_HPP_
# define RELEVANT_HPP_

#include "IComponent.hpp"
#include <unordered_map>
#include <functional>


namespace nts
{
  class			Relevant;

  typedef nts::IComponent *(nts::Relevant::*func)(const std::string &) const;

  class			Relevant
  {
  public:
    Relevant();
    ~Relevant() {};
    typedef nts::IComponent *(nts::Relevant::*func)(const std::string &) const;
    IComponent		*createComponent(const std::string &type, const std::string &value);

    std::unordered_map<std::string, func> const		&getTable() const;

  private:
    IComponent		*create4001(const std::string &value) const;
    IComponent		*create4008(const std::string &value) const;
    IComponent		*create4011(const std::string &value) const;
    IComponent		*create4013(const std::string &value) const;
    IComponent		*create4017(const std::string &value) const;
    IComponent		*create4030(const std::string &value) const;
    IComponent		*create4040(const std::string &value) const;
    IComponent		*create4069(const std::string &value) const;
    IComponent		*create4071(const std::string &value) const;
    IComponent		*create4081(const std::string &value) const;
    IComponent		*create4094(const std::string &value) const;
    IComponent		*create4514(const std::string &value) const;
    IComponent		*create4801(const std::string &value) const;
    IComponent		*create2716(const std::string &value) const;
    IComponent		*createInput(const std::string &value) const;
    IComponent		*createOutput(const std::string &value) const;
    std::unordered_map<std::string, func>	_tabFunc;
  };
}

#endif /* !RELEVANT_HPP_ */
