/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-hugo.mouraud
** File description:
** Snake
*/

#include "Snake.hpp"

std::unique_ptr<arcade::IGameModule> _open = nullptr;

arcade::Snake::Snake() : _map(), _snakeMap()
{
    _printScore = std::make_unique<Score>();
	srand(time(NULL));
	_snakeMap = {};
	_keys = {};
	_score = 0;
	_speed = 0;
	initPlayer();
	initMap();
	initScore();
	initClock();
}

arcade::Snake::~Snake()
{
}

void arcade::Snake::initPlayer(void)
{
    float x = 19, y = 15;

    for (int i = 0; i < 4; i++) {
        std::pair<float, float> pos(x + i, y);
        _posPlayer.push_back(pos);
    }

    _posFood = {10, 10};
}

void arcade::Snake::initKeys(Event keys)
{
    switch (keys) {
    case Event::up:
        _posPlayer[0].first--;
        break;
    case Event::down:
        _posPlayer[0].first++;
        break;
    case Event::left:
        _posPlayer[0].second--;
        break;
    case Event::right:
        _posPlayer[0].second++;
        break;
    default:
        break;
    }
}

void arcade::Snake::initMap(void)
{
	_map = std::make_unique<Map>();
	_map->openMap("Games/src/Snake/Snake.map");
	_snakeMap = _map->getMap();
}

void arcade::Snake::initScore(void)
{
	std::vector<float> pos = {0, 0};
	std::vector<float> posSpeed = {0, 45};
	std::vector<float> size = {25};
	_text = std::make_unique<arcade::Text>("Score: " + std::to_string(_score), pos, size, arcade::Color({255, 255, 255, 255}));
	_defaultSpeed = std::make_unique<arcade::Text>("Speed: x" + std::to_string(_speed), posSpeed, size, arcade::Color({255, 255, 255, 255}));
}

void arcade::Snake::initClock(void)
{
	auto clock = std::chrono::steady_clock::now();
	_slow = 0.3;
	_time = clock;
	_useKeys = up;
}

bool arcade::Snake::spawnFood()
{
    _posFood[0] = rand() % 25;
    _posFood[1] = 5 + rand() % 23;

    bool valid = true;
    for (const auto& pos : _posPlayer) {
        if (_posFood[0] == pos.first && _posFood[1] == pos.second) {
            valid = false;
            break;
        }
    }
    if (valid && _snakeMap[_posFood[0]][_posFood[1]] != 'X') {
        return (true);
    } else {
        return (spawnFood());
	}
	return (true);
}


int arcade::Snake::eatFood(Event keys)
{
	int dx = 0;
	int dy = 0;

	switch (keys) {
		case up: dx = -1; dy = 0; break;
		case down: dx = 1; dy = 0; break;
		case left: dx = 0; dy = -1; break;
		case right: dx = 0; dy = 1; break;
		default: return 0;
	}
	if (_posPlayer[0].first + dx == (int) _posFood.at(0) && _posPlayer[0].second + dy == (int) _posFood.at(1)) {
		_posPlayer.push_back(std::make_pair(_posPlayer.back().first - 1, _posPlayer.back().second));
		return (1);
	}
	return (0);
}

void arcade::Snake::event(Event keys)
{
	_keys = keys;
}

void arcade::Snake::loadHighScore()
{

}
void arcade::Snake::updateScore()
{

}
int arcade::Snake::getScore()
{
	return (_score);
}

void arcade::Snake::quit()
{
	exit(0);
}
void arcade::Snake::resume()
{

}

void arcade::Snake::speedPlayer(Event keys)
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

void arcade::Snake::pause(IDisplayModule &graphical, Event keys)
{
	float tmp = _slow;

	while (keys != enter) {
		while (graphical.pollEvent(keys))
			keys = graphical.useEvent();
		graphical.clear();
		graphical.drawBack();
		arcade::Text pause("Snake - Pause", {300, 250}, {45});
		graphical.drawText(pause);
		_slow = 10000;
		graphical.display();
	}
	_slow = tmp;
}
bool arcade::Snake::isPaused()
{
	return (true);
}

void arcade::Snake::setMovePlayer(IDisplayModule &graphical)
{
    auto clock = std::chrono::steady_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::duration<float>>(clock - _time);

    if (time.count() > _slow) {
        if (_keys != none && snakeBack(_keys))
            _useKeys = _keys;
        snakeMove(_useKeys, graphical);
        _time = clock;
    }
}

bool arcade::Snake::snakeBack(Event keys)
{
    if (_posPlayer.size() == 1)
        return (true);
    int xDiff = _posPlayer[1].first - _posPlayer[0].first;
    int yDiff = _posPlayer[1].second - _posPlayer[0].second;

    switch (keys) {
        case up:
            return xDiff != -1;
        case down:
            return xDiff != 1;
        case left:
            return yDiff != -1;
        case right:
            return yDiff != 1;
        default:
            return (false);
    }
}

bool arcade::Snake::endSnake(void)
{
	if (_posPlayer[0].first < 0 || _posPlayer[0].first >= 27 || _posPlayer[0].second < 0 || _posPlayer[0].second >= 27)
		return (true);
	for (auto it = _posPlayer.begin() + 1; it != _posPlayer.end(); ++it) {
		if (_posPlayer[0] == *it)
			return (true);
	}
	return (_snakeMap[_posPlayer[0].first][_posPlayer[0].second] == 'X');
}

void arcade::Snake::posPlayer(void)
{
	auto tmp = _posPlayer;
	for (int i = 1 ; i < (int) _posPlayer.size() ; i++) {
		_posPlayer[i].first = tmp[i - 1].first;
		_posPlayer[i].second = tmp[i - 1].second;
	}
}

void arcade::Snake::snakeMove(Event keys, IDisplayModule &graphical)
{
    if (eatFood(keys)) {
        spawnFood();
        _score++;
        _text->setText("Score: " + std::to_string(_score));
		if (_score % 5 == 0) {
			_slow -= 0.05;
			_speed++;
			_defaultSpeed->setText("Speed: x" + std::to_string(_speed));
		}
    }
	posPlayer();
	initKeys(keys);
    if (endSnake()) {
		_printScore->drawScore(graphical);
		quit();
	}
}

void arcade::Snake::drawRectangle(float y, float x, IDisplayModule &graphical, arcade::Color color)
{
	if (graphical.graphicalName() != "ncurses") {
		y = y * 22;
		x = x * 22;
		arcade::Sprite sprite({22, 22}, {x, y}, color);
		graphical.draw(sprite);
	} else {
		y = y * 2;
		x = x * 2;
		arcade::Sprite sprite({2, 2}, {x, y}, color);
		graphical.draw(sprite);
	}
}

void arcade::Snake::printPlayer(IDisplayModule &graphical)
{
	arcade::Color foodColor = {255, 0, 0, 255};
	arcade::Color playerColor = {244, 255, 255, 255};

	drawRectangle(_posFood[0], _posFood[1], graphical, foodColor);
	for (float i = 0 ; i < (float) _posPlayer.size() ; i++) {
		if (i == 0)
			drawRectangle(_posPlayer[i].first, _posPlayer[i].second, graphical, playerColor);
		else
			drawRectangle(_posPlayer[i].first, _posPlayer[i].second, graphical, playerColor);
	}
}

void arcade::Snake::printMap(IDisplayModule &graphical)
{
	arcade::Color rectColor = {0, 244, 244, 244};

	for (int j = 0 ; j < 27; j++) {
		for (int i = 0 ; i < 28; i++) {
			if (_snakeMap[j][i] == 'X')
				drawRectangle(j, i, graphical, rectColor);
		}
	}
}

void arcade::Snake::run(IDisplayModule &graphical)
{
	_text->setPosition({0, 0});
	graphical.clear();
	printPlayer(graphical);
	printMap(graphical);
	graphical.drawText(*_text);
	graphical.drawText(*_defaultSpeed);
	graphical.display();
}

void arcade::Snake::restart()
{

}

extern "C" arcade::IGameModule *openGame()
{
	_open = std::make_unique<arcade::Snake>();
	return (_open.get());
}
