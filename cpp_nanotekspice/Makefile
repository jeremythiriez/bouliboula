##
## Makefile for Makefile in /home/jeremy/tech2/piscine/rush/cpp_gkrellm
##
## Made by jeremy thiriez
## Login   <jeremy@epitech.net>
##
## Started on  Sun Jan 22 03:04:26 2017 jeremy thiriez
## Last update Sun Mar  5 23:07:27 2017 etienne.dewever@epitech.eu
##

RM	= rm -f

NAME	= nanotekspice

CPPFLAGS	+= -W -Wall -Wextra -Werror -std=c++11 -I./include

SRC	= main.cpp

OBJ	= $(SRC:.cpp=.o)

all:	libs $(NAME)

libs:
	make -C src/

$(NAME):	$(OBJ)
		g++ $(OBJ) -o $(NAME) -L. -lnanotekspice

clean:
		make clean -C src/
		$(RM) $(OBJ)

fclean:	clean
	make fclean -C src/
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all libs clean fclean re
