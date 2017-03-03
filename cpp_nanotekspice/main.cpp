//
// main.cpp for main.cpp in /home/jeremy/tech2/CPP/cpp_nanotekspice
//
// Made by jeremy thiriez
// Login   <jeremy@epitech.net>
//
// Started on  Mon Feb  6 19:01:45 2017 jeremy thiriez
// Last update Fri Mar  3 09:07:45 2017 jeremy thiriez
//

#include <iostream>
#include "IComponent.hpp"
#include "Parser.hpp"
#include "NanoTekSpice.hpp"
#include "4071.hpp"

int		main(int ac, char **av)
{

  (void)ac;
  (void)av;

  nts::NanoTekSpice nano(av);

  nano.execution();

  return (0);
}
