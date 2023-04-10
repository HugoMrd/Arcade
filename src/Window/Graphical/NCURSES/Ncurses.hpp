/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-hugo.mouraud
** File description:
** Ncurses
*/

/**
 * @file Ncurses.hpp
 * @brief This class implements the Ncurses library to provide graphical display.
 * @author Hugo Mouraud/Lucas MECHIN/Victor Doucet
 * @date 2023
 */

#ifndef NCURSES_HPP_
    #define NCURSES_HPP_
    #include <memory>
    #include <map>
    #include <functional>
    #include <unordered_map>
    #include "ColorNcurses.hpp"
    #include "../../../System/Event.hpp"
    #include "../../../System/Macro.hpp"
    #include "../../../Error/Error.hpp"
    #include "../../Color.hpp"
    #include "../../IDisplayModule.hpp"

namespace arcade {
    /**
     * @class Ncurses
     * @brief Ncurses graphics module implementation
    */
    class Ncurses : public IDisplayModule {
        public:

        /**
         * @brief Construct a new Ncurses object
         *
         * @param name Name of the graphics library.
         */
        Ncurses(std::string const &name = "Arcade - NCURSES graphics");

        /**
         * @brief Destroy the Ncurses object
         *
         */
        ~Ncurses();

        /**
         * @brief Draw a pixel to the screen.
         *
         * @param x The x position of the pixel to draw.
         * @param y The y position of the pixel to draw.
         * @param c The character to draw.
         * @param color The color to use when drawing the pixel.
         */
        void drawPixel(int x, int y, char c, const Color &color);

        /**
         * @brief Create the display window
         *
         * @param name Name of the display window
         */
        void create(std::string const &name) override;

        /**
         * @brief Open the display window
         *
         * @return true if the display window was successfully opened
         * @return false if the display window could not be opened
         */
        bool open(void) override;

        /**
         * @brief Close the display window
         *
         */
        void close(void) override;

        /**
         * @brief Clear the screen
         *
         */
        void clear(void) override;

        /**
         * @brief Update the display window
         *
         */
        void display(void) override;

        /**
         * @brief Poll for an event
         *
         * @param event The event to poll for
         * @return true if the event was polled successfully
         * @return false if the event could not be polled
         */
        bool pollEvent(Event) override;

        /**
         * @brief Draw a sprite to the screen
         *
         * @param sprite The sprite to draw
         */
        void draw(arcade::Sprite &sprite) override;

        /**
         * @brief Get the next event
         *
         * @return arcade::Event The next event
         */
        arcade::Event useEvent() override;

        /**
         * @brief Draw a text to the screen
         *
         * @param text The text to draw
         */
        void drawText(arcade::Text &text) override;

        /**
         * @brief Draw the background
         *
         */
        void drawBack(void) override;

        /**
         * @brief Get the graphical name
         *
         * @return std::string The graphical name
         */
        std::string graphicalName() const override {
            return ("ncurses");
        };
        private:

            /**
             * @brief The last key that was pressed
             *
             */
            int _key_ch;
        private:

            /**
             * @brief Mapping of keyboard keys to arcade events
             * This private member variable is an unordered map that maps integer values
             * representing keyboard keys to corresponding arcade events. The map is
             * initialized with the following values:
             * {-1, arcade::Event::none}
             * {'\n', arcade::Event::enter}
             * {KEY_UP, arcade::Event::up}
             * {KEY_DOWN, arcade::Event::down}
             * {KEY_LEFT, arcade::Event::left}
             * {KEY_RIGHT, arcade::Event::right}
             * {'\e', arcade::Event::escape}
             * {KEY_BACKSPACE, arcade::Event::backspace}
             * @see arcade::Event
             */
            const std::unordered_map<int, arcade::Event> _keyboard = {
                {-1, arcade::Event::none},
                {'\n', arcade::Event::enter},
                {KEY_UP, arcade::Event::up},
                {KEY_DOWN, arcade::Event::down},
                {KEY_LEFT, arcade::Event::left},
                {KEY_RIGHT, arcade::Event::right},
                {'\e', arcade::Event::escape},
                {KEY_BACKSPACE, arcade::Event::backspace},
            };
    };
}

#endif /* !NCURSES_HPP_ */
