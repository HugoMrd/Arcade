##
## EPITECH PROJECT, 2023
## B-OOP-400-PAR-4-1-arcade-hugo.mouraud
## File description:
## Makefile
##

CC	=	g++

RM	=	rm

NAME_NCURSES	=	../../../../lib/arcade_ncurses.so

SRC_NCURSES	=	Ncurses.cpp			\
				../../Text.cpp		\
				../../Sprite.cpp	\

OBJ_NCURSES	=	$(SRC_NCURSES:.cpp=.o)

CXXFLAGS	=	-I.

CXXFLAGS 	+= 	-std=c++20 -Wall -Wextra -Werror -g3 -rdynamic -fPIC

LDFLAGS_NCURSES	=	-shared -lncurses

all: $(NAME_NCURSES)

$(NAME_NCURSES):	$(OBJ_NCURSES)
		$(CC) $(OBJ_NCURSES) -o $(NAME_NCURSES) $(LDFLAGS_NCURSES)

clean:
	$(RM) -f $(OBJ_NCURSES)

fclean: clean
	$(RM) -f $(NAME_NCURSES)
	$(RM) -f *~
	$(RM) -f *.gcno
	$(RM) -f *.gcda
	$(RM) -f *.o
	$(RM) -f a.out
	$(RM) -f vgcore*

re: fclean all

.PHONY: re fclean clean all
