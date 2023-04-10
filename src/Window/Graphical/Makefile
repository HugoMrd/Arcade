##
## EPITECH PROJECT, 2023
## B-OOP-400-PAR-4-1-arcade-hugo.mouraud
## File description:
## Makefile
##

all:
	make -C ./NCURSES
	make -C ./SDL
	make -C ./SFML

clean:
	make clean -C ./NCURSES
	make clean -C ./SDL
	make clean -C ./SFML

fclean: clean
	make fclean -C ./NCURSES
	make fclean -C ./SDL
	make fclean -C ./SFML

re: fclean all

.PHONY: all clean fclean re
