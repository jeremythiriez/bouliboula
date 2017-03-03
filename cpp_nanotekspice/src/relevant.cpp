//w
// relevant.cpp for relevant.cpp in /home/jeremy/tech2/CPP/cpp_nanotekspice/src
//
// Made by jeremy thiriez
// Login   <jeremy@epitech.net>
//
// Started on  Tue Feb  7 19:10:24 2017 jeremy thiriez
// Last update Fri Mar  3 05:34:14 2017 jeremy thiriez
//

#include "Relevant.hpp"

nts::Relevant::Relevant()
{
  _tabFunc = {
    // {"4001", &nts::Relevant::create4001},
    // {"4008", &nts::Relevant::create4008},
    // {"4011", &nts::Relevant::create4011},
    // {"4013", &nts::Relevant::create4013},
    // {"4017", &nts::Relevant::create4017},
    // {"4030", &nts::Relevant::create4030},
    // {"4040", &nts::Relevant::create4040},
    // {"4069", &nts::Relevant::create4069},
    {"4071", &nts::Relevant::create4071},
    // {"4081", &nts::Relevant::create4081},
    // {"4094", &nts::Relevant::create4094},
    // {"4514", &nts::Relevant::create4514},
    // {"4801", &nts::Relevant::create4801},
    // {"2716", &nts::Relevant::create2716},
    // {"Input", &nts::Relevant::createInput},
    // {"Output", &nts::Relevant::createOutput}
  };
}

nts::IComponent		*nts::Relevant::createComponent(const std::string &type,
					 const std::string &value)
{
  return _tabFunc[type](value);
}

nts::IComponent		*nts::Relevant::create4071(const std::string &value)
{
  return (new Comp4071(value));
}
