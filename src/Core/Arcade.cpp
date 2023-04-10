/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-hugo.mouraud
** File description:
** Arcade
*/

#include "Arcade.hpp"

static const std::regex REGEX("^[a-zA-Z0-9_]*.so");

arcade::Arcade::Arcade(const std::string &path)
{
    _listGame = 0;
    _listGraphical = 0;
    _graphicalLister.push_back(path);
    _gameLister = {};
    _check = false;
    _menu = std::make_unique<Menu>();
    _menu->loadGraphicalMenu(_graphicalLister);
    _menu->loadGameMenu(_gameLister);
    _namePlayer = std::make_unique<Name>();
    _score = std::make_unique<Score>();
}

bool arcade::Arcade::checkGame(void)
{
    auto game_it = std::find(_gameLister.begin(), _gameLister.end(), _check);
    if (game_it != _gameLister.end()) {
        _gameLoader.destroyGame();
        if (_gameLoader.Game(_check)) {
            _game = _gameLoader.getGame();
            return (true);
        } else
            return (false);
    }
    return (true);
}

bool arcade::Arcade::checkGraphical(void)
{
    auto graphical_it = std::find(_graphicalLister.begin(), _graphicalLister.end(), _check);
    if (graphical_it != _graphicalLister.end()) {
        _graphicalLoader.destroyGraphical();
        if (_graphicalLoader.Graphical(_check)) {
            _graphical = _graphicalLoader.getGraphical();
            return (true);
        } else
            return (false);
    }
    return (true);
}

bool arcade::Arcade::checkMenu(void)
{
    if (_check.empty())
        return false;
    if (!checkGame())
        return (false);
    if (!checkGraphical())
        return (false);
    return (true);
}

bool arcade::Arcade::runMenu()
{
    _menu->setGraphicalMenu(_graphicalLister);
    _menu->setGameMenu(_gameLister);
    _check = _menu->openMenu(*_graphical);
    if (!checkMenu())
        return (false);
    return (true);
}

int arcade::Arcade::run(void)
{
    arcade::Event keys = {};
    bool check = true;

    if (!_graphicalLoader.Graphical(_graphicalLister[_listGraphical])
        || !_gameLoader.Game(_gameLister[_listGame]))
        return (84);
    _graphical = _graphicalLoader.getGraphical();
    _game = _gameLoader.getGame();
    _namePlayer->createName(*_graphical);
    if (!runMenu()) {
        _gameLoader.destroyGame();
        _graphicalLoader.destroyGraphical();
        return (84);
    }
    while (check && loadingArcade(keys) != 0);
    _namePlayer->setScore(_game->getScore());
    _namePlayer->writeScore();
    _gameLoader.destroyGame();
    _graphicalLoader.destroyGraphical();
    return (0);
}

int arcade::Arcade::loadingArcade(Event keys)
{
    bool quit = false;

    while (!quit) {
        while (_graphical->pollEvent(keys)) {
            keys = _graphical->useEvent();
            if (keys == arcade::Event::escape) {
                quit = true;
                break;
            }
            if (keys == arcade::Event::a)
                _score->drawScore(*_graphical);
            if (keys == arcade::Event::p)
                _game->pause(*_graphical, keys);
            if (keys == arcade::Event::m) {
                _gameLoader.destroyGame();
                runMenu();
            }
            _game->speedPlayer(keys);
            restartGame(keys);
            switchGame(keys);
            switchGraphical(keys);
            _game->event(keys);
        }
        if (!quit) {
            _game->setMovePlayer(*_graphical);
            _game->run(*_graphical);
            return (1);
        }
    }
    return (0);
}

void arcade::Arcade::restartGame(Event keys)
{
    if (keys == r) {
        _gameLoader.destroyGame();
        _gameLoader.Game(_gameLister[_listGame]);
        _game = _gameLoader.getGame();
    }
}

void arcade::Arcade::switchGame(Event keys)
{
    if (keys == g) {
        std::size_t switchSize = _gameLister.size();
        _gameLoader.destroyGame();
        _listGame = (_listGame + 1) % switchSize;
        _gameLoader.Game(_gameLister[_listGame % switchSize]);
        _game = _gameLoader.getGame();
    }
}

void arcade::Arcade::switchGraphical(Event keys)
{
    if (keys == l) {
        std::size_t switchSize = _graphicalLister.size();
        _graphicalLoader.destroyGraphical();
        _listGraphical = (_listGraphical + 1) % switchSize;
        _graphicalLoader.Graphical(_graphicalLister[_listGraphical]);
        _graphical = _graphicalLoader.getGraphical();
    }
}
