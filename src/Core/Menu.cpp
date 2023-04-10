/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-hugo.mouraud
** File description:
** Menu
*/

#include "Menu.hpp"

arcade::Menu::Menu()
{
    _cursorMouse.first = 0;
    _cursorMouse.second = 0;
}

void arcade::Menu::loadGameMenu(std::vector<std::string> &gameLister)
{
    const std::regex libraryNameRegex("^[a-zA-Z0-9_]*\\.so$");
    dirent **directoryList;
    int directorySize = scandir("./Games", &directoryList, nullptr, alphasort);
    int index = 0;

    if (directorySize < 0) {
        perror("scandir");
        return;
    }
    while (index < directorySize) {
        std::string libraryName = directoryList[index]->d_name;
        if (std::regex_match(libraryName, libraryNameRegex) &&
            std::find(gameLister.begin(), gameLister.end(), "./Games/" + libraryName) == gameLister.end()) {
            gameLister.emplace_back("./Games/" + libraryName);
        }
        index++;
    }
    free(directoryList);
}

void arcade::Menu::loadGraphicalMenu(std::vector<std::string> &graphicalLister)
{
    const std::regex libraryNameRegex("^[a-zA-Z0-9_]*\\.so$");
    dirent **directoryList;
    int directorySize = scandir("./lib", &directoryList, nullptr, alphasort);
    int index = 0;

    if (directorySize < 0) {
        perror("scandir");
        return;
    }
    while (index < directorySize) {
        std::string libraryName = directoryList[index]->d_name;
        if (std::regex_match(libraryName, libraryNameRegex) &&
            std::find(graphicalLister.begin(), graphicalLister.end(), "./lib/" + libraryName) == graphicalLister.end()) {
            graphicalLister.emplace_back("./lib/" + libraryName);
        }
        index++;
    }
    free(directoryList);
}

bool arcade::Menu::setupMove(void)
{
    const int maxIndex = (_cursorMouse.first == 0) ? _graphicalLister.size() - 1 : _gameLister.size() - 1;

    return (_cursorMouse.second < maxIndex);
}

void arcade::Menu::moveMenu(arcade::Event keys)
{
    switch (keys) {
        case up:
            if (_cursorMouse.second > 0)
                --_cursorMouse.second;
            break;
        case down:
            if (setupMove())
                ++_cursorMouse.second;
            break;
        case left:
            if (_cursorMouse.first > 0 && _cursorMouse.second < static_cast<int>(_graphicalLister.size()))
                --_cursorMouse.first;
            break;
        case right:
            if (_cursorMouse.first < 1 && _cursorMouse.second < static_cast<int>(_gameLister.size()))
                ++_cursorMouse.first;
            break;
        default:
            break;
    }
}

void arcade::Menu::setGameMenu(std::vector<std::string> gameLister)
{
    _gameLister = gameLister;
}

void arcade::Menu::setGraphicalMenu(std::vector<std::string> graphicalLister)
{
    _graphicalLister = graphicalLister;
}

void arcade::Menu::printGameMenu(arcade::IDisplayModule &game, std::vector<float> pos)
{
    arcade::Text text("Games:", {460, 80}, {80});
    float changePos = 0;
    float movePos = pos.at(0) / 20;
    int incr = 0;

    game.drawBack();
    game.drawText(text);
	for (auto &elem: _gameLister) {
        arcade::Text loopText(elem.substr(elem.find('/') + 1), {(pos.at(1) + 400) / 2, (pos.at(0) / 4 + changePos)}, {25});
        if (_cursorMouse.first == 1 && _cursorMouse.second == incr)
            loopText.setColor({0, 244, 244, 244});
        game.drawText(loopText);
        changePos += movePos;
        incr++;
    }
}

void arcade::Menu::printGraphicalMenu(arcade::IDisplayModule &graphical, std::vector<float> pos)
{
    arcade::Text text("Libraries:", {80, 80}, {80});
    float changePos = 0;
    float movePos = pos.at(0) / 20;
    int incr = 0;

    graphical.drawText(text);
	for (auto &elem: _graphicalLister) {
        arcade::Text loopText(elem.substr(elem.find('/') + 1), {pos.at(1) / 4, (pos.at(0) / 4 + changePos)}, {25});
        if (_cursorMouse.first == 0 && _cursorMouse.second == incr)
            loopText.setColor({0, 244, 244, 244});
        graphical.drawText(loopText);
        changePos += movePos;
        incr++;
    }
}

std::string arcade::Menu::openMenu(IDisplayModule &graphical)
{
    arcade::Event keys = {};

    while (keys != Event::escape) {
        std::vector<float> gamePos = {800, 600};
        std::vector<float> graphicalPos = {800, 600};
        while (graphical.pollEvent(keys)) {
            keys = graphical.useEvent();
            if (keys == enter) {
                if (_cursorMouse.first == 1)
                    return _gameLister[_cursorMouse.second];
                else
                    return _graphicalLister[_cursorMouse.second];
            }
            moveMenu(keys);
        }
        graphical.clear();
        printGameMenu(graphical, gamePos);
        printGraphicalMenu(graphical, graphicalPos);
        graphical.display();
    }
    return ("");
}
