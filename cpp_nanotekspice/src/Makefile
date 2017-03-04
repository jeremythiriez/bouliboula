##
## Makefile for Makefile in /home/jeremy/tech2/piscine/rush/cpp_gkrellm
##
## Made by jeremy thiriez
## Login   <jeremy@epitech.net>
##
## Started on  Sun Jan 22 03:04:26 2017 jeremy thiriez
## Last update Sun Mar  5 23:08:42 2017 etienne.dewever@epitech.eu
##

RM	= rm -f

NAME	= ../libnanotekspice.a

CPPFLAGS	+= -W -Wall -Wextra -Werror -std=c++11 -I../include

SRC	= parser.cpp \
	  nanotekspice.cpp \
	  circuit.cpp \
	  Input.cpp \
	  Output.cpp \
	  relevant.cpp \
	  comp4071.cpp \
	  comp4001.cpp \
	  comp4030.cpp \
	  comp4069.cpp \
	  comp4081.cpp \
	  comp4011.cpp \
	  AComponent.cpp \

OBJ	= $(SRC:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
