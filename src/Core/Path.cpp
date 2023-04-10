/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-hugo.mouraud
** File description:
** Path
*/

#include "Path.hpp"

bool arcade::Path::pathFile(char **av)
{
    std::ifstream file(av[1]);
    if (file.fail())
        return (false);
    return (true);
}
