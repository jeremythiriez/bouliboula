//
// Circuit.hpp for Circuit.hpp in /home/jeremy/tech2/CPP/cpp_nanotekspice/include
//
// Made by jeremy thiriez
// Login   <jeremy@epitech.net>
//
// Started on  Tue Feb  7 10:12:27 2017 jeremy thiriez
// Last update Sun Mar  5 23:05:30 2017 etienne.dewever@epitech.eu
//

#ifndef CIRCUIT_HPP
# define CIRCUIT_HPP

# include <unordered_map>
# include "IComponent.hpp"
# include "Parser.hpp"
# include "Input.hpp"
# include "Output.hpp"
# include "Relevant.hpp"

namespace nts
{
  class			Parser;

  class			Circuit : public IComponent
  {
  private:
    std::string						_fileName;
    nts::Parser						*_parser;
    std::unordered_map<std::string, Input *>		_input;
    std::unordered_map<std::string, Output *>		_output;
    std::unordered_map<std::string, IComponent *>	_components;
    nts::Relevant					_factory;
    bool						clock;
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
    std::unordered_map<std::string, Input*>		getInput() const;
    std::unordered_map<std::string, Output*>		getOutput() const;
    std::unordered_map<std::string, IComponent*>	getComponent() const;

    void						addElement(std::string const &type,
								   std::string const &name);
    IComponent						*searchComponent(std::string const &ref);

    nts::Relevant const					&getFactory() const;
  };
}

#endif /* !CIRCUIT_HPP */
