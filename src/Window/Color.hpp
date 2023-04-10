/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-hugo.mouraud
** File description:
** Color
*/

#ifndef COLOR_HPP_
    #define COLOR_HPP_
    #include <cstdint>

namespace arcade {
    /**
     * @brief The Color struct represents a color in RGBA format.
     */
    struct Color {
        std::uint8_t r; /**< The red component of the color. */
        std::uint8_t g; /**< The green component of the color. */
        std::uint8_t b; /**< The blue component of the color. */
        std::uint8_t a; /**< The alpha component of the color. */

        /**
         * @brief Checks if the current color is equal to a given RGBA color.
         * @param r The red component of the color.
         * @param g The green component of the color.
         * @param b The blue component of the color.
         * @param a The alpha component of the color.
         * @return True if the colors are equal, false otherwise.
         */
        bool isRGBA(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a) const {
            return (Color::r == r && Color::g == g && Color::b == b && Color::a == a);
        }

        /**
         * @brief Compares two colors for inequality.
         * @param opColor The color to compare with.
         * @return True if the colors are not equal, false otherwise.
         */
        bool operator!=(const Color &opColor) {
            bool ret = false;

            if (r != opColor.r || g != opColor.g || b != opColor.b)
                ret = true;

            return (ret);
        }

        /**
         * @brief Compares two colors for equality.
         * @param opColor The color to compare with.
         * @return True if the colors are equal, false otherwise.
         */
        bool operator==(const Color &opColor) {
            bool ret = false;

            if (r == opColor.r && g == opColor.g && b == opColor.b)
                ret = true;

            return (ret);
        }
    };
};

#endif /* !COLOR_HPP_ */
