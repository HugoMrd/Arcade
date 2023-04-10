##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

CC	=	g++

SRC	=	src/Core/Arcade.cpp				\
		src/Core/GameLoader.cpp			\
		src/Core/GraphicalLoader.cpp	\
		src/Core/Map.cpp				\
		src/Core/Menu.cpp				\
		src/Core/Name.cpp				\
		src/Core/Path.cpp				\
		src/Core/Score.cpp				\
		src/Window/Sprite.cpp 			\
		src/Window/Text.cpp 			\

SRCM 	= 	src/Main.cpp

OBJ	=	$(SRC:.cpp=.o)	\
		$(SRCM:.cpp=.o)

RM	=	rm

NAME	=	arcade

CXXFLAGS	=	-I src/

CXXFLAGS	+=	-std=c++20 -Wall -Wextra -Werror -g3 -rdynamic -fPIC

LDFLAGS		=	-ldl

all:	core graphicals games

core:	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

graphicals:
	make -C ./src/Window/Graphical

games:
	make -C ./Games

doc:
	doxygen -g config_file
	sed -i 's/RECURSIVE              = NO/RECURSIVE              = YES/g' config_file
	sed -i 's/USE_MDFILE_AS_MAINPAGE =/USE_MDFILE_AS_MAINPAGE = README.md/g' config_file
	doxygen config_file
	firefox html/index.html

cleandoc:
	rm -rf html
	rm -rf latex
	rm config_file

clean:
	make clean -C ./src/Window/Graphical
	make clean -C ./Games
	$(RM) -f $(OBJ)

fclean: clean
	make fclean -C ./src/Window/Graphical
	make fclean -C ./Games
	$(RM) -f $(NAME)
	$(RM) -f *~
	$(RM) -f *.gcno
	$(RM) -f *.gcda
	$(RM) -f *.o
	$(RM) -f a.out
	$(RM) -f vgcore*

re: fclean all

.PHONY: re fclean clean all
