/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-hugo.mouraud
** File description:
** Main
*/

#include <iostream>
#include "Core/Arcade.hpp"
#include "Core/Path.hpp"

int main(int ac, char **av)
{
    arcade::Path path;

    if (ac < 2 || ac > 2) {
        std::cerr << "Error: Bad arguments -> ";
        for (int i = 0; i < ac; i++)
            std::cerr << av[i] << ' ';
        std::cerr << std::endl;
        return (84);
    }
    if (ac == 2) {
        if (path.pathFile(av) == false) {
            std::cerr << "Error: Path failed -> " << av[1] << std::endl;
            return (84);
        }
        arcade::Arcade core(av[1]);
        return (core.run());
    }
    return (0);
}
