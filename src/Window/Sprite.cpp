/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-hugo.mouraud
** File description:
** Sprite
*/

#include "Sprite.hpp"

arcade::Sprite::Sprite(std::vector<float> size, std::vector<float> pos, arcade::Color color)
{
	_size = size;
	_pos = pos;
	for (float i = 0; i < size.at(0); i++) {
		for (float j = 0; j < size.at(1); j++)
			_color.push_back(color);
	}
}

float arcade::Sprite::getH(void) const
{
	return (_size.at(1));
}

float arcade::Sprite::getW(void) const
{
	return (_size.at(0));
}

float arcade::Sprite::getY(void) const
{
	return (_pos.at(1));
}

float arcade::Sprite::getX(void) const
{
	return (_pos.at(0));
}

void arcade::Sprite::setH(float height)
{
	_size.at(height);
}

void arcade::Sprite::setW(float width)
{
	_size.at(width);
}

void arcade::Sprite::setY(float y)
{
	_pos.at(y);
}

void arcade::Sprite::setX(float x)
{
	_pos.at(x);
}

void arcade::Sprite::setPosition(std::vector<float> pos)
{
	_pos = pos;
}

std::vector<float> arcade::Sprite::getPosition(void) const
{
	return (_pos);
}

void arcade::Sprite::setSize(std::vector<float> size)
{
	_size = size;
}

std::vector<float> arcade::Sprite::getSize(void) const
{
	return (_size);
}

void arcade::Sprite::setSprite(std::vector<float> pos, arcade::Color color)
{
	_color[pos.at(1) + pos.at(0) * getW()] = color;
}

arcade::Color arcade::Sprite::getSprite(std::vector<float> pos) const
{
	return _color[pos.at(0) + pos.at(1) * getW()];
}

std::vector<arcade::Color> &arcade::Sprite::getSpriteArray()
{
	return _color;
}
