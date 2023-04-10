/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-hugo.mouraud
** File description:
** ColorNcurses
*/

/**
* @file ColorNcurses.hpp
* @brief This file defines the ColorNcurses class, which handles color conversions and pair initialization for ncurses.
*/

#ifndef COLOR_NCURSES_HPP_
    #define COLOR_NCURSES_HPP_

#include <functional>
#include <array>
#include <ncurses.h>
#include "../../Color.hpp"

/**
* @brief A class that handles color conversions and pair initialization for ncurses.
*/

/**
* @brief The default color value.
*/
static constexpr int DEFAULTCOLOR = 80;

/**
* @brief The bad color value.
*/
static constexpr int BADCOLOR = -42;

/**
 * @brief A vector of color pairs.
 */
std::vector<std::pair<arcade::Color, arcade::Color>> _colors;

/**
* @brief Converts an integer percentage value to a double percentage value.
* @param pourcentage The integer percentage value to convert.
* @return The double percentage value.
*/
static double convertToPercentage(int pourcentage) {
	return (((double)pourcentage / 255.0) * 100.0);
}

/**
* @brief Check if a color is a predefined color in ncurses.
* @param r_pct The red percentage value.
* @param g_pct The green percentage value.
* @param b_pct The blue percentage value.
* @return The ncurses color value or BADCOLOR if the color is not recognized.
*/
static int checkColor(const double r_pct, const double g_pct, const double b_pct) {
	if (r_pct > DEFAULTCOLOR && g_pct > DEFAULTCOLOR && b_pct > DEFAULTCOLOR)
		return (COLOR_WHITE);
	if (r_pct < DEFAULTCOLOR && g_pct < DEFAULTCOLOR && b_pct < DEFAULTCOLOR)
		return (COLOR_BLACK);
	if (r_pct > DEFAULTCOLOR && g_pct > DEFAULTCOLOR)
		return (COLOR_YELLOW);
	if (r_pct > DEFAULTCOLOR && b_pct > DEFAULTCOLOR)
		return (COLOR_MAGENTA);
	if (g_pct > DEFAULTCOLOR && b_pct > DEFAULTCOLOR)
		return (COLOR_CYAN);
	if (r_pct > DEFAULTCOLOR)
		return (COLOR_RED);
	if (g_pct > DEFAULTCOLOR)
		return (COLOR_GREEN);
	if (b_pct > DEFAULTCOLOR)
		return (COLOR_BLUE);
	return (BADCOLOR);
}

/**
 * @brief A vector of color conversion functions.
 */
static const std::vector<std::function<int(const arcade::Color &)>> _color = {
	[](const arcade::Color &color) {
		const auto r_pct = convertToPercentage(color.r);
		const auto g_pct = convertToPercentage(color.g);
		const auto b_pct = convertToPercentage(color.b);
		if (checkColor(r_pct, g_pct, b_pct) != BADCOLOR)
			return (checkColor(r_pct, g_pct, b_pct));
		return (BADCOLOR);
	}
};

/**
* @brief Converts a color to an ncurses color pair value.
* @param color The color to convert.
* @return The ncurses color pair value or BADCOLOR if the color is not recognized.
*/
int convertColor(const arcade::Color &color) {
    for (size_t i = 0; i < _color.size(); ++i) {
        int col = _color[i](color);
        if (col != BADCOLOR)
            return (col);
    }
    return (BADCOLOR);
}

/**
* @brief Finds the index of a color pair in the _colors vector.
* @param firstColor The first color of the color pair.
* @param secondColor The second color of the color pair.
* @return The index of the color pair or BADCOLOR if the color pair is not found.
*/
int findColor(const arcade::Color &firstColor, const arcade::Color &secondColor) {
    for (size_t i = 0; i < _colors.size(); ++i) {
        if (_colors[i].first == firstColor && _colors[i].second == secondColor)
            return (static_cast<int>(i));
    }
    return (BADCOLOR);
}

/**
 * @brief Initializes an ncurses color pair from two colors and stores it in the _colors vector.
 * @param firstColor The first color of the color pair.
 * @param secondColor The second color of the color pair.
 * @param pair The ncurses color pair value to set.
 */
void ncrusesColor(const arcade::Color &firstColor, const arcade::Color &secondColor, int &pair)
{
    int i = findColor(firstColor, secondColor);
    if (i < 0) {
        _colors.emplace_back(firstColor, secondColor);
        i = static_cast<int>(_colors.size()) - 1;
    }
    pair = i + 1;
    if (init_pair(pair, convertColor(firstColor), convertColor(secondColor)) == ERR) {
        pair = BADCOLOR;
        return;
    }
    attron(COLOR_PAIR(pair));
}

#endif /* !COLOR_NCURSES_HPP_ */
