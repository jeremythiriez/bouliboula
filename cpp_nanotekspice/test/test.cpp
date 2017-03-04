//
// test.cpp for test in /mnt/dump/deweve_e/tek2/nano/cpp_nanotekspice/test
//
// Made by etienne.dewever@epitech.eu
// Login   <deweve_e@epitech.eu>
//
// Started on  Sun Mar  5 21:38:07 2017 etienne.dewever@epitech.eu
// Last update Sat Mar  4 19:46:07 2017 jeremy thiriez
//

#include <iostream>
#include "IComponent.hpp"
#include "4081.hpp"
#include "4071.hpp"
#include "Output.hpp"
#include "Input.hpp"

void		componentSamePin()
{
  nts::IComponent	*output = new nts::Output("o");

  output->SetLink(1, *output, 1);
  std::cout << "TEST LINK IN SAME PIN : "  << std::endl;
  try
    {
      output->Compute();
      output->Dump();
      std::cout << "OK" << std::endl;
    }
  catch (std::exception &e)
    {
      std::cout << "KO" << std::endl;
      std::cerr << e.what() << std::endl;
    }
}

void		infiniteLoop()
{
  nts::IComponent	*orGate = new nts::Comp4071("Or");
  nts::Input		*input = new nts::Input("Input");
  nts::Output		*output = new nts::Output("Output");

  input->setValue(nts::TRUE);
  orGate->SetLink(1, *input, 1);
  orGate->SetLink(3, *orGate, 2);
  output->SetLink(1, *orGate, 3);
  output->Compute();
  output->Dump();
}

int		main()
{
  infiniteLoop();
  componentSamePin();
  return (1);
}
