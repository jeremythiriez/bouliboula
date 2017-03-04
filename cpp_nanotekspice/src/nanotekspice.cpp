//
// nanotekspice.cpp for nanotekspice.cpp in /home/jeremy/tech2/CPP/cpp_nanotekspice/src
//
// Made by jeremy thiriez
// Login   <jeremy@epitech.net>
//
// Started on  Tue Feb  7 08:47:14 2017 jeremy thiriez
// Last update Sat Mar  4 19:38:48 2017 jeremy thiriez
//

#include <iostream>
#include "NanoTekSpice.hpp"

nts::NanoTekSpice::NanoTekSpice(char **av, int ac)
  : _av(av)
{
  if (ac < 2)
    throw nts::NanoTekSpice::Error("Give a file and commands");
  _circuit = new Circuit(av);
  this->func["display"] = &nts::NanoTekSpice::display;
  this->func["simulate"] = &nts::NanoTekSpice::simulate;
  this->func["dump"] = &nts::NanoTekSpice::dump;
  this->func["loop"] = &nts::NanoTekSpice::loop;
  this->func["exit"] = &nts::NanoTekSpice::exit;
  for (int idx = 2; idx < ac; idx++)
    {
      this->executeCommand(av[idx]);
      this->simulate();
    }
  this->running = true;
}

nts::Circuit		*nts::NanoTekSpice::getCircuit() const
{
  return _circuit;
}

void			nts::NanoTekSpice::executeCommand(std::string const &line)
{
  std::string		input;

  if (func.find(line) != func.end())
    (this->*func[line])();
  else
    {
      input = line.substr(0, line.find("="));
      if (this->_circuit->getInput().find(input) != this->_circuit->getInput().end())
	this->assign(line);
    }
}

void			nts::NanoTekSpice::execution()
{
  std::string		line = "";

  this->simulate();
  this->display();
  std::cout << ">>";
  while (this->running && std::getline(std::cin, line))
    {
      this->executeCommand(line);
      if (this->running)
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
  for(auto &e : this->_circuit->getComponent())
    e.second->Dump();
}

void			nts::NanoTekSpice::loop()
{
  for(;;)
    this->simulate();
}

void			nts::NanoTekSpice::assign(std::string line)
{
  nts::Tristate		trist;
  std::string		input = line.substr(0, line.find("="));
  std::string		value = line.substr(line.find("=") + 1, line.size());

  if (value == "0")
    trist = nts::FALSE;
  else if (value == "1")
    trist = nts::TRUE;
  else
    trist = nts::UNDEFINED;
  this->_circuit->getInput()[input]->setValue(trist);
}

void			nts::NanoTekSpice::exit(void)
{
  this->running = false;
}
