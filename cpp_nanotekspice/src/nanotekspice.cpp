//
// nanotekspice.cpp for nanotekspice.cpp in /home/jeremy/tech2/CPP/cpp_nanotekspice/src
//
// Made by jeremy thiriez
// Login   <jeremy@epitech.net>
//
// Started on  Tue Feb  7 08:47:14 2017 jeremy thiriez
// Last update Fri Mar  3 10:49:12 2017 jeremy thiriez
//

#include <iostream>
#include "NanoTekSpice.hpp"

nts::NanoTekSpice::NanoTekSpice(char **av)
  : _av(av)
{
  _circuit = new Circuit(av);
  this->func["display"] = &nts::NanoTekSpice::display;
  this->func["simulate"] = &nts::NanoTekSpice::simulate;
  this->func["dump"] = &nts::NanoTekSpice::dump;
  this->func["loop"] = &nts::NanoTekSpice::loop;
  this->func["assign"] = &nts::NanoTekSpice::assign;
}

nts::Circuit		*nts::NanoTekSpice::getCircuit() const
{
  return _circuit;
}

void			nts::NanoTekSpice::execution()
{
  std::string		line = "";

  this->simulate();
  this->display();
  std::cout << ">>";
  while (std::getline(std::cin, line))
    {
      if (func.find(line) != func.end())
	{
	  (this->*func[line])();
	}
      std::cout << ">>";
    }
}

void			nts::NanoTekSpice::display()
{
  this->_circuit->DumpOutput();
}

void			nts::NanoTekSpice::simulate()
{
  this->_circuit->Compute();
}

void			nts::NanoTekSpice::dump()
{
  this->_circuit->Dump();
  for(auto e : this->_circuit->getComponent())
    e.second->Dump();
}

void			nts::NanoTekSpice::loop()
{
}

void			nts::NanoTekSpice::assign()
{

}
