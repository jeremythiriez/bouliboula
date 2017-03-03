//
// parser.hpp for parser.hpp in /home/jeremy/tech2/CPP/cpp_nanotekspice/include
//
// Made by jeremy thiriez
// Login   <jeremy@epitech.net>
//
// Started on  Mon Feb  6 19:37:55 2017 jeremy thiriez
// Last update Sat Feb 11 20:50:13 2017 jeremy thiriez
//

#ifndef PARSER_HPP
# define PARSER_HPP

# include "IParser.hpp"
# include <fstream>
# include <string>
# include <vector>

namespace nts
{
  class			Parser : public IParser
  {
    enum		e_type {
	UNDEFINED = -1,
	CHIPSET,
	LINK
    };
   private:
    e_type					_mode;
    std::vector<std::vector<std::string>>	_feed;
    std::vector<std::string>			_componentName;
    std::vector<std::string>			_chipsetName;
  public:
    Parser();
    virtual ~Parser();
    Parser(Parser const& other);
    Parser const&			operator=(Parser const& other);
    virtual void			feed(std::string const& input);
    virtual void			parseTree(t_ast_node& root);
    virtual t_ast_node			*createTree();
    std::vector<std::vector<std::string>>	getFeed() const;
    void				checkComponent(std::string const& line);
    void				checkLink(std::string const& line);
  };
}

#endif /* !PARSER_HPP */
