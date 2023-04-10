##
## EPITECH PROJECT, 2023
## B-OOP-400-PAR-4-1-arcade-hugo.mouraud
## File description:
## Makefile
##

CC	=	g++

RM	=	rm

NAME_SFML	=	../../../../lib/arcade_sfml.so

SRC_SFML	=	Sfml.cpp			\
				../../Text.cpp		\
				../../Sprite.cpp	\

OBJ_SFML	=	$(SRC_SFML:.cpp=.o)

CXXFLAGS	=	-I.

CXXFLAGS 	+= 	-std=c++20 -Wall -Wextra -Werror -g3 -rdynamic -fPIC

LDFLAGS_SFML	=	-shared -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all: $(NAME_SFML)

$(NAME_SFML):	$(OBJ_SFML)
		$(CC) $(OBJ_SFML) -o $(NAME_SFML) $(LDFLAGS_SFML)

clean:
	$(RM) -f $(OBJ_SFML)

fclean: clean
	$(RM) -f $(NAME_SFML)
	$(RM) -f *~
	$(RM) -f *.gcno
	$(RM) -f *.gcda
	$(RM) -f *.o
	$(RM) -f a.out
	$(RM) -f vgcore*

re: fclean all

.PHONY: re fclean clean all
