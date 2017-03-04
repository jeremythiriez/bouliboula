//
// main.cpp for main.cpp in /home/jeremy/tech2/CPP/cpp_nanotekspice
//
// Made by jeremy thiriez
// Login   <jeremy@epitech.net>
//
// Started on  Mon Feb  6 19:01:45 2017 jeremy thiriez
// Last update Sun Mar  5 02:38:27 2017 etienne.dewever@epitech.eu
//

#include <iostream>
#include "IComponent.hpp"
#include "Parser.hpp"
#include "NanoTekSpice.hpp"
#include "4071.hpp"

int		main(int ac, char **av)
{
  nts::NanoTekSpice nano(av, ac);

  nano.execution();

  return (0);
}
