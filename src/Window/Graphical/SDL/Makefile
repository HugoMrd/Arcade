##
## EPITECH PROJECT, 2023
## B-OOP-400-PAR-4-1-arcade-hugo.mouraud
## File description:
## Makefile
##

CC	=	g++

RM	=	rm

NAME_SDL	=	../../../../lib/arcade_sdl2.so

SRC_SDL	=	Sdl.cpp				\
			../../Text.cpp		\
			../../Sprite.cpp	\

OBJ_SDL	=	$(SRC_SDL:.cpp=.o)

CXXFLAGS	=	-I.

CXXFLAGS 	+= 	-std=c++20 -Wall -Wextra -Werror -g3 -rdynamic -fPIC

LDFLAGS_SDL	=	-shared -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image

all: $(NAME_SDL)

$(NAME_SDL):	$(OBJ_SDL)
		$(CC) $(OBJ_SDL) -o $(NAME_SDL) $(LDFLAGS_SDL)

clean:
	$(RM) -f $(OBJ_SDL)

fclean: clean
	$(RM) -f $(NAME_SDL)
	$(RM) -f *~
	$(RM) -f *.gcno
	$(RM) -f *.gcda
	$(RM) -f *.o
	$(RM) -f a.out
	$(RM) -f vgcore*

re: fclean all

.PHONY: re fclean clean all
