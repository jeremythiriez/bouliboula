//
// NanoTekSpice.hpp for NanoTekSpice.hpp in /home/jeremy/tech2/CPP/cpp_nanotekspice/include
//
// Made by jeremy thiriez
// Login   <jeremy@epitech.net>
//
// Started on  Tue Feb  7 08:42:58 2017 jeremy thiriez
// Last update Fri Mar  3 09:06:33 2017 jeremy thiriez
//

#ifndef NANOTEKSPICE_HPP_
# define NANOTEKSPICE_HPP_

#include <string>
#include <map>
#include <functional>
#include "Circuit.hpp"

namespace nts
{
  class			NanoTekSpice
  {
  public:
    typedef void (nts::NanoTekSpice::*ptr)(void);
  private:
    char						**_av;
    Circuit						*_circuit;
    std::unordered_map<std::string, ptr>		func;
    public:
    NanoTekSpice(char **av);
    ~NanoTekSpice() {};
    Circuit		*getCircuit() const;
    void		display();
    void		simulate();
    void		dump();
    void		loop();
    void		execution();
    void		assign();
  };
}

#endif /* !NANOTEKSPICE_HPP_ */
