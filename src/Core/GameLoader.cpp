/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-hugo.mouraud
** File description:
** GameLoader
*/

#include "GameLoader.hpp"

arcade::GameLoader::GameLoader()
{
    _path = "";
    _game = nullptr;
    _openGame = nullptr;
}

arcade::GameLoader::~GameLoader()
{
    destroyGame();
}

bool arcade::GameLoader::checkGame(const std::string &path)
{
    std::regex gameName(R"(^.*arcade_.*\.so$)");

    if (!std::regex_match(path, gameName))
        return (false);
    std::ifstream file(path);
    if (file.fail())
        return (false);
    return (std::regex_match(path, gameName));
}

bool arcade::GameLoader::Game(const std::string &path)
{
    if (!checkGame(path))
        return (false);
    _openGame = dlopen(path.c_str(), RTLD_LAZY);
    if (_openGame == nullptr)
        return (false);
    auto *open = reinterpret_cast<arcade::IGameModule*(*)()>(dlsym(_openGame, "openGame"));
    if (open == nullptr) {
        std::cout << dlerror() << std::endl;
        dlclose(_openGame);
        _openGame = nullptr;
        return (false);
    }
    _game = open();
    return (true);
}

arcade::IGameModule *arcade::GameLoader::getGame(void)
{
    return (_game);
}

void arcade::GameLoader::destroyGame(void)
{
    if (_openGame != nullptr)
        dlclose(_openGame);
    _game = nullptr;
    _openGame = nullptr;
}
