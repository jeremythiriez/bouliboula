##
## Makefile for Makefile in /home/jeremy/tech2/piscine/rush/cpp_gkrellm
##
## Made by jeremy thiriez
## Login   <jeremy@epitech.net>
##
## Started on  Sun Jan 22 03:04:26 2017 jeremy thiriez
## Last update Fri Mar  3 03:42:49 2017 jeremy thiriez
##

RM	= rm -f

NAME	= nanotekspice

CPPFLAGS	+= -W -Wall -Wextra -Werror -std=c++14 -I./include
CPPFLAGS	+= -g3

SRC	= main.cpp \
	  src/parser.cpp \
	  src/nanotekspice.cpp \
	  src/circuit.cpp \
	  src/Input.cpp \
	  src/Output.cpp \
	  src/comp4071.cpp \

OBJ	= $(SRC:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
