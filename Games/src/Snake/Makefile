##
## EPITECH PROJECT, 2023
## B-OOP-400-PAR-4-1-arcade-hugo.mouraud
## File description:
## Makefile
##

CC	=	g++

RM	=	rm

NAME_SNAKE	=	../../arcade_snake.so

SRC_SNAKE	=	Snake.cpp						\
				../../../src/Core/Map.cpp		\
				../../../src/Core/Score.cpp		\
				../../../src/Window/Sprite.cpp	\
				../../../src/Window/Text.cpp	\

OBJ_SNAKE	=	$(SRC_SNAKE:.cpp=.o)

CXXFLAGS	=	-I.

CXXFLAGS 	+= 	-std=c++20 -Wall -Wextra -Werror -g3 -rdynamic -fPIC

LDFLAGS_SNAKE	=	-shared -lncurses

all: $(NAME_SNAKE)

$(NAME_SNAKE):	$(OBJ_SNAKE)
		$(CC) $(OBJ_SNAKE) -o $(NAME_SNAKE) $(LDFLAGS_SNAKE)

clean:
	$(RM) -f $(OBJ_SNAKE)

fclean: clean
	$(RM) -f $(NAME_SNAKE)
	$(RM) -f *~
	$(RM) -f *.gcno
	$(RM) -f *.gcda
	$(RM) -f *.o
	$(RM) -f a.out
	$(RM) -f vgcore*

re: fclean all

.PHONY: re fclean clean all
