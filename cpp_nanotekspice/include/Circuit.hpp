//
// Circuit.hpp for Circuit.hpp in /home/jeremy/tech2/CPP/cpp_nanotekspice/include
//
// Made by jeremy thiriez
// Login   <jeremy@epitech.net>
//
// Started on  Tue Feb  7 10:12:27 2017 jeremy thiriez
// Last update Fri Mar  3 07:05:57 2017 jeremy thiriez
//

#ifndef CIRCUIT_HPP
# define CIRCUIT_HPP

#include <unordered_map>
#include "IComponent.hpp"
#include "Parser.hpp"
#include "Input.hpp"
#include "Output.hpp"

namespace nts
{
  class			Circuit : public IComponent
  {
  private:
    std::string						_fileName;
    Parser						*_parser;
    // std::unordered_map<std::string, nts::Tristate>	valeInput;
    // std::unordered_map<std::string, nts::Tristate>	valeOuput;

    std::unordered_map<std::string, Input*>	_input;
    std::unordered_map<std::string, Output*>	_output;
    std::unordered_map<std::string, IComponent*>	_component;

  public:
    Circuit(char **av);
    virtual ~Circuit() {};
    nts::Tristate	Compute(size_t pin_num_this = 1);
    void		SetLink(size_t pin_num_this,
				nts::IComponent &component,
				size_t pin_num_target);
    void		Dump(void) const;
    void		DumpOutput(void) const;
    Parser		*getParser() const;
    std::unordered_map<std::string, Input*>	getInput() const;
    std::unordered_map<std::string, Output*>	getOutput() const;
    std::unordered_map<std::string, IComponent*>	getComponent() const;
  };
}

#endif /* !CIRCUIT_HPP */
