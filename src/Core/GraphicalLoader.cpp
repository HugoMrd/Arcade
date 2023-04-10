/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-hugo.mouraud
** File description:
** GraphicalLoader
*/

#include "GraphicalLoader.hpp"

arcade::GraphicalLoader::GraphicalLoader()
{
    _path = "";
    _graphical = nullptr;
    _openGraphical = nullptr;
}

arcade::GraphicalLoader::~GraphicalLoader()
{
    destroyGraphical();
}

bool arcade::GraphicalLoader::checkGraphical(const std::string &path)
{
    std::regex libName(R"(^.*arcade_.*\.so$)");

    std::cout << path << std::endl;
    if (!std::regex_match(path, libName))
        return (false);
    std::ifstream file(path);
    if (file.fail())
        return (false);
    return (std::regex_match(path, libName));
}

bool arcade::GraphicalLoader::Graphical(const std::string &path)
{
    if (!checkGraphical(path))
        return (false);
    _openGraphical = dlopen(path.c_str(), RTLD_LAZY);
    if (_openGraphical == nullptr)
        return (false);
    auto *open = reinterpret_cast<arcade::IDisplayModule*(*)()>(dlsym(_openGraphical, "openGraphical"));
    if (open == nullptr) {
        std::cout << dlerror() << std::endl;
        dlclose(_openGraphical);
        _openGraphical = nullptr;
        return (false);
    }
    _graphical = open();
    return (true);
}

arcade::IDisplayModule *arcade::GraphicalLoader::getGraphical(void)
{
    return (_graphical);
}

void arcade::GraphicalLoader::destroyGraphical(void)
{
    if (_openGraphical != nullptr)
        dlclose(_openGraphical);
    _graphical = nullptr;
    _openGraphical = nullptr;
}
