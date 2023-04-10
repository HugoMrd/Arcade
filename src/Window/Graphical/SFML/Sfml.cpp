/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-hugo.mouraud
** File description:
** Sfml
*/

#include "Sfml.hpp"

std::unique_ptr<arcade::IDisplayModule> _open = nullptr;

arcade::Sfml::Sfml(std::string const &name) : _font(), _text(), _window(), _texture(), _sprite(_texture)
{
	_font.loadFromFile("Resources/UniversCondensed.ttf");
	_text.setFont(_font);
	create(name);
	_texture.create(WINDOW_WIDTH, WINDOW_HEIGHT);
}

arcade::Sfml::~Sfml()
{
    if (open())
        _window.close();
}

void arcade::Sfml::create(std::string const &name)
{
    _window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), name,
                    sf::Style::Resize | sf::Style::Close);
}

bool arcade::Sfml::open(void)
{
	return (_window.isOpen());
}

void arcade::Sfml::close(void)
{
	if (open())
		_window.close();
}

void arcade::Sfml::clear(void)
{
	if (open())
		_window.clear({0, 0, 0, 255});
}

void arcade::Sfml::display(void)
{
	if (open())
		_window.display();
}

bool arcade::Sfml::pollEvent(arcade::Event)
{
    sf::Event event{};

    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            auto it = _keyboard.find(event.key.code);
            if (it != _keyboard.end())
                _keysEvent.push(it->second);
            else
                throw std::out_of_range("Key not found in keyboard map");
		}
	}
    return (!_keysEvent.empty());
}

void arcade::Sfml::draw(arcade::Sprite &sprite)
{
	sf::Sprite sfmlSPrite;
	int W = static_cast<unsigned int>(sprite.getW());
	int H = static_cast<unsigned int>(sprite.getH());
	float X = sprite.getX();
	float Y = sprite.getY();

	if (open()) {
		auto array = &sprite.getSpriteArray()[0];
		_texture.update((unsigned char *) array, W, H, 0, 0);
		sfmlSPrite.setTexture(_texture);
		sfmlSPrite.setPosition(X, Y);
		sfmlSPrite.setTextureRect({0, 0, W, H});
		_window.draw(sfmlSPrite);
	}
}

void arcade::Sfml::drawBack(void)
{
	sf::Sprite backgroundSprite;

	if (!_texture.loadFromFile("Resources/background.png"))
		throw Error("Failed loading ");
	if (open()) {
		backgroundSprite.setTexture(_texture);
		backgroundSprite.setPosition(0, 0);
		_window.draw(backgroundSprite);
	}
}

arcade::Event arcade::Sfml::useEvent()
{
	arcade::Event keys =_keysEvent.front();
	_keysEvent.pop();
	return (keys);
}

void arcade::Sfml::drawText(arcade::Text &text)
{
	auto col = text.getColor();

	if (open()) {
		_text.setFont(_font);
		_text.setString(text.getText());
		_text.setCharacterSize(text.getSize().at(0));
		_text.setPosition(text.getPosX(), text.getPosY());
		_text.setFillColor(sf::Color(col.r, col.g, col.b, col.a));
		_window.draw(_text);
	}
}

extern "C" arcade::IDisplayModule *openGraphical()
{
	_open = std::make_unique<arcade::Sfml>("Arcade - SFML graphics");
	return (_open.get());
}
