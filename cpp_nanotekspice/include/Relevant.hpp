//
// Relevant.hpp for Relevent.hpp in /home/jeremy/tech2/CPP/cpp_nanotekspice/include
//
// Made by jeremy thiriez
// Login   <jeremy@epitech.net>
//
// Started on  Tue Feb  7 18:54:57 2017 jeremy thiriez
// Last update Tue Feb  7 20:11:11 2017 jeremy thiriez
//

#ifndef RELEVANT_HPP_
# define RELEVANT_HPP_

#include "IComponent.hpp"
#include <unordered_map>
#include <functional>

typedef nts::IComponent *(*func)(const std::string &);

namespace nts
{
  class			Relevant
  {
  private:
    IComponent		*create4001(const std::string &value);
    IComponent		*create4008(const std::string &value);
    IComponent		*create4011(const std::string &value);
    IComponent		*create4013(const std::string &value);
    IComponent		*create4017(const std::string &value);
    IComponent		*create4030(const std::string &value);
    IComponent		*create4040(const std::string &value);
    IComponent		*create4069(const std::string &value);
    IComponent		*create4071(const std::string &value);
    IComponent		*create4081(const std::string &value);
    IComponent		*create4094(const std::string &value);
    IComponent		*create4514(const std::string &value);
    IComponent		*create4801(const std::string &value);
    IComponent		*create2716(const std::string &value);
    IComponent		*createInput(const std::string &value);
    IComponent		*createOutput(const std::string &value);
    std::unordered_map<std::string, func>	_tabFunc;
  public:
    Relevant();
    ~Relevant() {};
    IComponent		*createComponent(const std::string &type, const std::string &value);
  };
}

#endif /* !RELEVANT_HPP_ */
