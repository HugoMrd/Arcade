/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-hugo.mouraud
** File description:
** Ncurses
*/

#include <ncurses.h>
#include "Ncurses.hpp"

std::unique_ptr<arcade::IDisplayModule> _open = nullptr;

void arcade::Ncurses::drawPixel(int x, int y, char c, const Color &color)
{
	int pair = 0;

	ncrusesColor(color, color, pair);
	mvprintw(y, x, "%c", c);
	attroff(COLOR_PAIR(pair));
}

arcade::Ncurses::Ncurses(std::string const &name)
{
	create(name);
}

arcade::Ncurses::~Ncurses()
{
	endwin();
}

void arcade::Ncurses::create(std::string const &name)
{
	(void)name;
	initscr();
	noecho();
	cbreak();
	keypad(stdscr, true);
	set_escdelay(0);
	start_color();
	timeout(33);
}

bool arcade::Ncurses::open(void)
{
	return (true);
}

void arcade::Ncurses::close(void)
{
	endwin();
}

void arcade::Ncurses::clear(void)
{
	wclear(stdscr);
}

void arcade::Ncurses::display(void)
{
}

bool arcade::Ncurses::pollEvent(Event)
{
	_key_ch = getch();
	return (_key_ch != -1);
}

void arcade::Ncurses::draw(arcade::Sprite &sprite)
{
    for (int i = 0; i < (int)sprite.getH(); i++) {
        for (int j = 0; j < (int)sprite.getW(); j++) {
            auto px = static_cast<int>(sprite.getX() + j);
            auto py = static_cast<int>(sprite.getY() + i);
            Color value = sprite.getSprite({(float)j, (float)i});
            drawPixel(px, py, ' ', value);
        }
    }
}

void arcade::Ncurses::drawBack(void)
{

}

arcade::Event arcade::Ncurses::useEvent()
{
	const std::unordered_map<int, arcade::Event>::const_iterator& it = _keyboard.find(_key_ch);
	if (it != _keyboard.end())
		return (it->second);
	if (_key_ch >= 'A' && _key_ch <= 'Z')
		return static_cast<arcade::Event>(arcade::Event::a + (_key_ch - 'A'));
	if (_key_ch >= 'a' && _key_ch <= 'z')
		return static_cast<arcade::Event>(arcade::Event::a + (_key_ch - 'a'));
	return (arcade::Event::none);
}

void arcade::Ncurses::drawText(arcade::Text &text)
{
	bool isCyanColor = text.getColor().isRGBA(0, 244, 244, 244);

	if (isCyanColor) {
		init_pair(1, COLOR_CYAN, COLOR_BLACK);
		attron(COLOR_PAIR(1));
	}
	mvprintw(text.getPosY() / 20, text.getPosX() / 10, "%s", text.getText().c_str());
	if (isCyanColor)
		attroff(COLOR_PAIR(1));
}

extern "C" arcade::IDisplayModule *openGraphical()
{
	_open = std::make_unique<arcade::Ncurses>("Arcade - NCURSES graphics");
	return (_open.get());
}
