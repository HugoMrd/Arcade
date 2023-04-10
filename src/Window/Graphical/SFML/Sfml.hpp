/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-hugo.mouraud
** File description:
** Sfml
*/

#ifndef SFML_HPP_
    #define SFML_HPP
    #include <queue>
    #include <SFML/Graphics.hpp>
    #include <SFML/Audio.hpp>
    #include <iostream>
    #include <memory>
    #include <unordered_map>
    #include "../../IDisplayModule.hpp"
    #include "../../../System/Macro.hpp"
    #include "../../../Error/Error.hpp"

namespace arcade {
    /**
     * @class Sfml
     * @brief Sfml class is the graphical module that handles the display of games and menus
     */
    class Sfml : public IDisplayModule {
        public:

            /**
             * @brief Construct a new Sfml object
             *
             * @param name A string reference containing the name of the graphical module
             */
            Sfml(std::string const &name = "Arcade - SFML graphics");

            /**
             * @brief Destroy the Sfml object
             *
             */
            ~Sfml() override;

            /**
             * @brief Create a new window with a specific name and size
             *
             * @param name A string reference containing the name of the window
             */
            void create(std::string const &name) override;

            /**
             * @brief Open the window
             *
             * @return true if the window has been opened successfully, false otherwise
             */
            bool open(void) override;

            /**
             * @brief Close the window
             *
             */
            void close(void) override;

            /**
             * @brief Clear the window
             *
             */
            void clear(void) override;

            /**
             * @brief Update the display
             *
             */
            void display(void) override;

            /**
             * @brief Poll events
             *
             * @param event An arcade::Event enum value passed by reference
             * @return true if events have been polled successfully, false otherwise
             */
            bool pollEvent(Event event) override;

            /**
             * @brief Draw a sprite on the window
             *
             * @param sprite A Sprite object passed by reference
             */
            void draw(arcade::Sprite &sprite) override;

            /**
             * @brief Draw the background of the window
             *
             */
            void drawBack(void) override;

            /**
             * @brief Use the event queue to return an event
             *
             * @return An arcade::Event enum value
             */
            arcade::Event useEvent() override;

            /**
             * @brief Draw a text on the window
             *
             * @param text A Text object passed by reference
             */
            void drawText(arcade::Text &text) override;

            /**
             * @brief Returns the name of the graphical module
             *
             * @return A string containing the name of the graphical module
             */
            std::string graphicalName() const override {
                return ("sfml");
            };

        protected:
            sf::Font _font; /**< Font object */
            sf::Text _text; /**< Text object */
            sf::RenderWindow _window; /**< Window object */
            sf::Texture _texture; /**< Texture object */
            sf::Sprite _sprite; /**< Sprite object */
            std::queue<arcade::Event> _keysEvent; /**< Event queue */

        private:

            /**
             * @brief Keyboard keys mapping
             */
            const std::unordered_map<sf::Keyboard::Key, arcade::Event> _keyboard = {
                {sf::Keyboard::Unknown, arcade::Event::none},
                {sf::Keyboard::A, arcade::Event::a},
                {sf::Keyboard::B, arcade::Event::b},
                {sf::Keyboard::C, arcade::Event::c},
                {sf::Keyboard::D, arcade::Event::d},
                {sf::Keyboard::E, arcade::Event::e},
                {sf::Keyboard::F, arcade::Event::f},
                {sf::Keyboard::G, arcade::Event::g},
                {sf::Keyboard::H, arcade::Event::h},
                {sf::Keyboard::I, arcade::Event::i},
                {sf::Keyboard::J, arcade::Event::j},
                {sf::Keyboard::K, arcade::Event::k},
                {sf::Keyboard::L, arcade::Event::l},
                {sf::Keyboard::M, arcade::Event::m},
                {sf::Keyboard::N, arcade::Event::n},
                {sf::Keyboard::O, arcade::Event::o},
                {sf::Keyboard::P, arcade::Event::p},
                {sf::Keyboard::Q, arcade::Event::q},
                {sf::Keyboard::R, arcade::Event::r},
                {sf::Keyboard::S, arcade::Event::s},
                {sf::Keyboard::T, arcade::Event::t},
                {sf::Keyboard::U, arcade::Event::u},
                {sf::Keyboard::V, arcade::Event::v},
                {sf::Keyboard::W, arcade::Event::w},
                {sf::Keyboard::X, arcade::Event::x},
                {sf::Keyboard::Y, arcade::Event::y},
                {sf::Keyboard::Z, arcade::Event::z},
                {sf::Keyboard::Enter, arcade::Event::enter},
                {sf::Keyboard::Up, arcade::Event::up},
                {sf::Keyboard::Down, arcade::Event::down},
                {sf::Keyboard::Left, arcade::Event::left},
                {sf::Keyboard::Right, arcade::Event::right},
                {sf::Keyboard::Escape, arcade::Event::escape},
                {sf::Keyboard::BackSpace, arcade::Event::backspace},
            };
    };
}

#endif /* !SFML_HPP_ */
