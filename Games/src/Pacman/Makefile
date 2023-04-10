##
## EPITECH PROJECT, 2023
## B-OOP-400-PAR-4-1-arcade-hugo.mouraud
## File description:
## Makefile
##

CC	=	g++

RM	=	rm

NAME_PACMAN	=	../../arcade_pacman.so

SRC_PACMAN	=	Pacman.cpp						\
				../../../src/Core/Map.cpp		\
				../../../src/Window/Sprite.cpp	\
				../../../src/Window/Text.cpp	\

OBJ_PACMAN	=	$(SRC_PACMAN:.cpp=.o)

CXXFLAGS	=	-I.

CXXFLAGS 	+= 	-std=c++20 -Wall -Wextra -Werror -g3 -rdynamic -fPIC

LDFLAGS_PACMAN	=	-shared -lncurses

all: $(NAME_PACMAN)

$(NAME_PACMAN):	$(OBJ_PACMAN)
		$(CC) $(OBJ_PACMAN) -o $(NAME_PACMAN) $(LDFLAGS_PACMAN)

clean:
	$(RM) -f $(OBJ_PACMAN)

fclean: clean
	$(RM) -f $(NAME_PACMAN)
	$(RM) -f *~
	$(RM) -f *.gcno
	$(RM) -f *.gcda
	$(RM) -f *.o
	$(RM) -f a.out
	$(RM) -f vgcore*

re: fclean all

.PHONY: re fclean clean all
