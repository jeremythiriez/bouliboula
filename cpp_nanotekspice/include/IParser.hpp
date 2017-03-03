//
// IParser.hpp for IParser.hpp in /home/jeremy/tech2/CPP/cpp_nanotekspice/include
//
// Made by jeremy thiriez
// Login   <jeremy@epitech.net>
//
// Started on  Mon Feb  6 19:25:46 2017 jeremy thiriez
// Last update Tue Feb  7 02:16:50 2017 jeremy thiriez
//

#ifndef IPARSER_HPP
# define IPARSER_HPP

# include <string>
# include <vector>

namespace nts
{
  enum class ASTNodeType : int
  {
    DEFAULT = -1,
      NEWLINE = 0,
      SECTION,
      COMPONENT,
      LINK,
      LINK_END,
      STRING
      };

  typedef struct	s_ast_node
  {
    s_ast_node(std::vector<struct s_ast_node*> *children)
      : children(children) {}
    std::string		lexem;
    ASTNodeType		type;
    std::string		value;
    std::vector<struct s_ast_node*> *children;
  }			t_ast_node;

  class IParser
  {
  public:
    virtual void	feed(std::string const& input) = 0;
    virtual void	parseTree(t_ast_node& root) = 0;
    virtual t_ast_node	*createTree() = 0;
    virtual ~IParser() {};
  };
}

#endif /* !IPARSER_HPP */
