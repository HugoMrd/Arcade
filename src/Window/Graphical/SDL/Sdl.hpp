/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-hugo.mouraud
** File description:
** Sdl
*/

/**
 * @file Sdl.hpp
 * @brief Sdl class header file
 */

#ifndef SDL_HPP_
    #define SDL_HPP_

#include <memory>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "../../../System/Event.hpp"
#include "../../../System/Macro.hpp"
#include "../../Sprite.hpp"
#include "../../Text.hpp"
#include "../../IDisplayModule.hpp"

namespace arcade {

    /**
     * @class Sdl
     * @brief SDL graphics module implementation
     */
    class Sdl : public IDisplayModule {
        public:

            /**
             * @brief Constructor of Sdl class
             * @param name Name of the graphics module
             */
            Sdl(std::string const &name = "Arcade - SDL graphics");

            /**
             * @brief Destructor of Sdl class
             */
            ~Sdl() override;

            /**
             * @brief Create a window
             * @param name Name of the window
             */
            void create(std::string const &name) override;

            /**
             * @brief Open the window
             * @return true if the window is opened, false otherwise
             */
            bool open(void) override;

            /**
             * @brief Close the window
             */
            void close(void) override;

            /**
             * @brief Clear the window
             */
            void clear(void) override;

            /**
             * @brief Display the window
             */
            void display(void) override;

            /**
             * @brief Check if an event is in the queue
             * @param event Event to check
             * @return true if the event is in the queue, false otherwise
             */
            bool pollEvent(Event) override;

            /**
             * @brief Draw a sprite on the window
             * @param sprite Sprite to draw
             */
            void draw(arcade::Sprite &sprite) override;

            /**
             * @brief Get the next event in the queue
             * @return The next event in the queue
             */
            arcade::Event useEvent() override;

            /**
             * @brief Draw a text on the window
             * @param text Text to draw
             */
            void drawText(arcade::Text &text) override;

            /**
             * @brief Draw the background of the window
             */
            void drawBack(void) override;

            /**
             * @brief Get the name of the graphics module
             * @return The name of the graphics module
             */
            std::string graphicalName() const override {
                return ("sdl");
            };

        protected:
            TTF_Font *_font; ///< SDL font used for text drawing
            std::queue<arcade::Event> _keysEvent; ///< Queue of events
            SDL_Window *_window; ///< SDL window
            SDL_Renderer *_renderer; ///< SDL renderer

        private:

            /**
             * @brief Keyboard keys mapping
             */
            const std::unordered_map<int, arcade::Event> _keyboard = {
                {SDLK_UNKNOWN, arcade::Event::none},
                {SDLK_a, arcade::Event::a},
                {SDLK_b, arcade::Event::b},
                {SDLK_c, arcade::Event::c},
                {SDLK_d, arcade::Event::d},
                {SDLK_e, arcade::Event::e},
                {SDLK_f, arcade::Event::f},
                {SDLK_g, arcade::Event::g},
                {SDLK_h, arcade::Event::h},
                {SDLK_i, arcade::Event::i},
                {SDLK_j, arcade::Event::j},
                {SDLK_k, arcade::Event::k},
                {SDLK_l, arcade::Event::l},
                {SDLK_m, arcade::Event::m},
                {SDLK_n, arcade::Event::n},
                {SDLK_o, arcade::Event::o},
                {SDLK_p, arcade::Event::p},
                {SDLK_q, arcade::Event::q},
                {SDLK_r, arcade::Event::r},
                {SDLK_s, arcade::Event::s},
                {SDLK_t, arcade::Event::t},
                {SDLK_u, arcade::Event::u},
                {SDLK_v, arcade::Event::v},
                {SDLK_w, arcade::Event::w},
                {SDLK_x, arcade::Event::x},
                {SDLK_y, arcade::Event::y},
                {SDLK_z, arcade::Event::z},
                {SDLK_RETURN, arcade::Event::enter},
                {SDLK_UP, arcade::Event::up},
                {SDLK_DOWN, arcade::Event::down},
                {SDLK_LEFT, arcade::Event::left},
                {SDLK_RIGHT, arcade::Event::right},
                {SDLK_ESCAPE, arcade::Event::escape},
                {SDLK_BACKSPACE, arcade::Event::backspace},
            };
    };
}

#endif /* !SDL_HPP_ */
