/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-hugo.mouraud
** File description:
** Text
*/

#include "Text.hpp"

arcade::Text::Text(const std::string &text, std::vector<float> pos, std::vector<float> size, arcade::Color color)
{
    _text = text;
    _pos = pos;
    _size = size;
    _color = color;
}

arcade::Text::~Text()
{
    _text = "";
    _pos = std::vector<float>();
    _size = std::vector<float>();
    _color = {};
}

void arcade::Text::setPosition(std::vector<float> pos)
{
    _pos = pos;
}

std::vector<float> arcade::Text::getPosition(void) const
{
    return (_pos);
}

void arcade::Text::setSize(std::vector<float> size)
{
    _size = size;
}

std::vector<float> arcade::Text::getSize(void) const
{
    return (_size);
}

void arcade::Text::setColor(arcade::Color color)
{
    _color = color;
}

arcade::Color arcade::Text::getColor(void) const
{
    return (_color);
}

void arcade::Text::setText(const std::string &text)
{
    _text = text;
}

std::string arcade::Text::getText(void) const
{
    return (_text);
}

void arcade::Text::setPosX(float posX)
{
    _pos.at(posX);
}

float arcade::Text::getPosX(void)
{
    return (_pos.at(0));
}

float arcade::Text::getX(void)
{
    return (_x);
}

void arcade::Text::setPosY(float posY)
{
    _pos.at(posY);
}

float arcade::Text::getPosY(void)
{
    return (_pos.at(1));
}

float arcade::Text::getY(void)
{
    return (_y);
}