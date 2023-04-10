/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-hugo.mouraud
** File description:
** Pacman
*/

#include "Pacman.hpp"

std::unique_ptr<arcade::IGameModule> _open = nullptr;

arcade::Pacman::Pacman() : _map(), _pacmanMap()
{
	_score = 0;
	_speed = 0;
	_pacmanMap = {};
	_keys = {};
	_posPlayer = {20, 14};
	initMap();
	initScore();
	initGhost();
	initClock();
}

arcade::Pacman::~Pacman()
{

}

void arcade::Pacman::event(Event keys)
{
	_keys = keys;
}

void arcade::Pacman::loadHighScore()
{

}

void arcade::Pacman::updateScore()
{

}

int arcade::Pacman::getScore()
{
	return (_score);
}

void arcade::Pacman::quit()
{

}

void arcade::Pacman::resume()
{

}

void arcade::Pacman::speedPlayer(Event keys)
{
	if (keys == s) {
		_slow -= 0.05;
		_speed += 1;
		_defaultSpeed->setText("Speed: x" + std::to_string(_speed));
	}
	if (keys == d) {
		_slow += 0.05;
		_speed -= 1;
		_defaultSpeed->setText("Speed: x" + std::to_string(_speed));
	}
}

void arcade::Pacman::pause(IDisplayModule &graphical, Event keys)
{
	float tmp = _slow;

	while (keys != enter) {
		while (graphical.pollEvent(keys))
			keys = graphical.useEvent();
		graphical.clear();
		graphical.drawBack();
		arcade::Text pause("Pacman - Pause", {300, 250}, {45});
		graphical.drawText(pause);
		_slow = 10000;
		graphical.display();
	}
	_slow = tmp;
}

bool arcade::Pacman::isPaused()
{
	return (true);
}

void arcade::Pacman::initMap(void)
{
	_map = std::make_unique<Map>();
	_map->openMap("Games/src/Pacman/Pacman.map");
	_pacmanMap = _map->getMap();
}

void arcade::Pacman::initScore(void)
{
	std::vector<float> pos = {0, 0};
	std::vector<float> posSpeed = {0, 45};
	std::vector<float> size = {25};
	_text = std::make_unique<arcade::Text>("Score: " + std::to_string(_score), pos, size, arcade::Color({255, 255, 255, 255}));
	_defaultSpeed = std::make_unique<arcade::Text>("Speed: x" + std::to_string(_speed), posSpeed, size, arcade::Color({255, 255, 255, 255}));

}

void arcade::Pacman::initGhost(void)
{
	_posGhost.emplace_back(12, 13);
	_posGhost.emplace_back(13, 13);
	_posGhost.emplace_back(12, 15);
	_posGhost.emplace_back(13, 15);
}

void arcade::Pacman::initClock(void)
{
	auto clock = std::chrono::steady_clock::now();
	_slow = 0.3;
	_time = clock;
	_useKeys = up;
}

void arcade::Pacman::run(IDisplayModule &graphical)
{
	_text->setPosition({0, 0});
	graphical.clear();
	printMap(graphical);
	printGhost(graphical);
	graphical.drawText(*_text);
	graphical.drawText(*_defaultSpeed);
	graphical.display();
}

void arcade::Pacman::printGhost(IDisplayModule &graphical)
{
	drawRectangle(_posPlayer.at(0), _posPlayer.at(1), graphical, {255, 210, 0, 255});
	for (std::size_t i = 0 ; i < _colorGhost.size() ; i++)
		drawRectangle((_posGhost[i].first), (_posGhost[i].second), graphical, _colorGhost[i]);
}

void arcade::Pacman::ghostMove(void)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(-1, 1);

	for (auto& ghost : _posGhost) {
		int dx, dy;
		do {
			dx = dis(gen);
			dy = dis(gen);
		} while (dx == 0 && dy == 0);
		float x = ghost.first + dx;
		float y = ghost.second + dy;
		if (isValidPosition(x, y)) {
			ghost.first = x;
			ghost.second = y;
		}
	}
}

bool arcade::Pacman::isValidPosition(float x, float y)
{
	if (x < 0 || x >= 27 || y < 0 || y >= 27)
		return false;
	int ix = static_cast<int>(x);
	int iy = static_cast<int>(y);
	return (_pacmanMap[iy][ix] != 'X');
}

void arcade::Pacman::pacmanMove(arcade::Event keys)
{
	float row = static_cast<float>(_posPlayer[0] + _upAndDown[keys]);
	float col = static_cast<float>(_posPlayer[1] + _leftAndRight[keys]);

	if (row < 0 || row >= _pacmanMap.size() || col < 0 || col >= _pacmanMap[0].size() || _pacmanMap[row][col] == 'X')
		return;
	if (_pacmanMap[row][col] == '.' || _pacmanMap[row][col] == 'o') {
		_score += _pacmanMap[row][col] == '.' ? 1 : 4;
		_text->setText("Score: " + std::to_string(_score));
		_pacmanMap[row][col] = ' ';
	}
	_posPlayer[0] = row;
	_posPlayer[1] = col;
}

void arcade::Pacman::setMovePlayer(IDisplayModule &graphical)
{
    auto clock = std::chrono::steady_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::duration<float>>(clock - _time);

	(void) graphical;
    if (time.count() <= _slow)
        return;
    if (_keys == none) {
        if (_useKeys == none)
            return;
        pacmanMove(_useKeys);
    } else {
        pacmanMove(_keys);
        _useKeys = _keys;
        _keys = none;
    }
	ghostMove();
    _time = clock;
}

void arcade::Pacman::printMap(IDisplayModule &graphical)
{
	arcade::Color rectColor = {0, 244, 244, 244};
    arcade::Color foodColor = {255, 210, 0, 255};

	for (int j = 0 ; j < 27; j++) {
		for (int i = 0 ; i < 27; i++) {
			if (_pacmanMap[j][i] == 'X')
				drawRectangle(j, i, graphical, rectColor);
			else if (_pacmanMap[j][i] == '.' || _pacmanMap[j][i] == 'o')
				drawFood(j, i, graphical, foodColor, _pacmanMap[j][i] == 'o');
		}
	}
}

void arcade::Pacman::drawRectangle(float y, float x, IDisplayModule &graphical, arcade::Color color)
{
	if (graphical.graphicalName() != "ncurses") {
		y = y * 22;
		x = x * 18;
		arcade::Sprite sprite({18, 22}, {x + 125, y}, color);
		graphical.draw(sprite);
	} else {
		y = y * 2;
		x = x * 2;
		arcade::Sprite sprite({2, 2}, {x, y}, color);
		graphical.draw(sprite);
	}
}

void arcade::Pacman::drawFood(float y, float x, IDisplayModule &graphical, arcade::Color color, bool bonus)
{
	if (graphical.graphicalName() != "ncurses") {
		y = y * 22;
		x = x * 18;
		arcade::Sprite sprite({6, 8}, {x + 131, y + 6}, color);
		graphical.draw(sprite);
		if (bonus) {
			arcade::Sprite bonus({10, 14}, {x + 129, y + 3}, {244, 144, 50, 244});
			graphical.draw(bonus);
		}
	} else {
		y = y * 2;
		x = x * 2;
		arcade::Sprite sprite({1.666, 1.375}, {x, y}, color);
		graphical.draw(sprite);
		if (bonus) {
			arcade::Sprite bonus({1.111, 1.273}, {x, y}, {244, 144, 50, 244});
			graphical.draw(bonus);
		}
	}
}

void arcade::Pacman::restart()
{

}

extern "C" arcade::IGameModule *openGame()
{
	_open = std::make_unique<arcade::Pacman>();
	return (_open.get());
}
