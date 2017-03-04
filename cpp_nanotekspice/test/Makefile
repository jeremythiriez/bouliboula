##
## Makefile for Makefile in /home/jeremy/tech2/piscine/rush/cpp_gkrellm
##
## Made by jeremy thiriez
## Login   <jeremy@epitech.net>
##
## Started on  Sun Jan 22 03:04:26 2017 jeremy thiriez
## Last update Sat Mar  4 19:46:57 2017 jeremy thiriez
##

RM	= rm -f

NAME	= nanotekspice

CPPFLAGS	+= -W -Wall -Wextra -Werror -std=c++14 -I../include

SRC	= test.cpp

OBJ	= $(SRC:.cpp=.o)

all:	libs $(NAME)

libs:
	make -C ../src/

$(NAME):	$(OBJ)
		g++ $(OBJ) -o $(NAME) -L.. -lnanotekspice

clean:
		make clean -C ../src/
		$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
