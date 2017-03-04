//
// parser.hpp for parser.hpp in /home/jeremy/tech2/CPP/cpp_nanotekspice/include
//
// Made by jeremy thiriez
// Login   <jeremy@epitech.net>
//
// Started on  Mon Feb  6 19:37:55 2017 jeremy thiriez
// Last update Sun Mar  5 22:51:53 2017 etienne.dewever@epitech.eu
//

#ifndef PARSER_HPP
# define PARSER_HPP

# include <fstream>
# include <string>
# include <vector>
# include <stdexcept>
# include "IParser.hpp"
# include "IComponent.hpp"
# include "Circuit.hpp"

namespace nts
{
  class			Circuit;

  class			Parser : public IParser
  {
  public:
    enum		e_type {
      UNDEFINED = -1,
      CHIPSET,
      LINK
    };

    class		Error : public std::exception
    {
    private:
      std::string	_msg;
    public:
      Error(std::string const &other) {this->_msg = other;};
      ~Error() throw() {};
      char const	*what() const throw()
      {
	return _msg.c_str();
      }
    };
  public:
    Parser(nts::Circuit &parent);
    virtual ~Parser();
    Parser(Parser const& other);
    Parser const&			operator=(Parser const& other);
    virtual void			feed(std::string const& input);
    virtual void			parseTree(t_ast_node& root);
    virtual t_ast_node			*createTree();
    std::vector<std::vector<std::string>> const &	getFeed() const;
    void				checkComponent(std::string const& line);
    void				checkLink(std::string const& line);

    void				setLink(t_ast_node *link);
    void				createChipset(t_ast_node *chipsets);

    static t_ast_node			*create(std::string const ref, ASTNodeType type,
						t_ast_node *child);
    nts::Circuit const			&getParent() const;
  private:
    e_type					_mode;
    std::vector<std::vector<std::string>>	_feed;
    std::vector<std::string>			_componentName;
    std::vector<std::string>			_chipsetName;
    nts::Circuit				&_parent;
  };
}

#endif /* !PARSER_HPP */
