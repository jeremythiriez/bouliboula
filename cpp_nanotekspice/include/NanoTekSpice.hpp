//
// NanoTekSpice.hpp for NanoTekSpice.hpp in /home/jeremy/tech2/CPP/cpp_nanotekspice/include
//
// Made by jeremy thiriez
// Login   <jeremy@epitech.net>
//
// Started on  Tue Feb  7 08:42:58 2017 jeremy thiriez
// Last update Sun Mar  5 22:57:13 2017 etienne.dewever@epitech.eu
//

#ifndef NANOTEKSPICE_HPP_
# define NANOTEKSPICE_HPP_

# include <string>
# include <map>
# include <functional>
# include <stdexcept>
# include "Circuit.hpp"

namespace nts
{
  class			NanoTekSpice
  {
  public:
    class		Error : public std::exception
    {
    private:
      std::string	_msg;
    public:
      Error(std::string const &msg) {this->_msg = msg;};
      ~Error() throw() {};
      char const	*what() const throw()
      {
	return _msg.c_str();
      }
    };

  public:
    typedef void (nts::NanoTekSpice::*ptr)(void);
  private:
    char						**_av;
    Circuit						*_circuit;
    std::unordered_map<std::string, ptr>		func;
    bool						running;
  public:
    NanoTekSpice(char **av, int ac);
    ~NanoTekSpice() {};
    Circuit		*getCircuit() const;
    void		executeCommand(std::string const &line);
    void		display();
    void		simulate();
    void		dump();
    void		loop();
    void		execution();
    void		exit();
    void		assign(std::string);
  };
}

#endif /* !NANOTEKSPICE_HPP_ */
