/**
 * @file IDisplayModule.hpp
 * @brief Interface for a display module.
 */

#ifndef IDISPLAYMODULE_HPP_
    #define IDISPLAYMODULE_HPP_

#include <string>
#include "Text.hpp"
#include "Sprite.hpp"
#include "../System/Event.hpp"

namespace arcade {
    /**
     * @class IDisplayModule
     * @brief Interface for a display module.
     */
    class IDisplayModule {
        public:

        /**
         * @brief Destructor for the IDisplayModule class.
         */
        virtual ~IDisplayModule() = default;

        /**
         * @brief Creates the display window.
         * @param name The name of the window.
         */
        virtual void create(std::string const &name) = 0;

        /**
         * @brief Polls for an event in the display window.
         * @param event The event to poll for.
         * @return True if the event was found, false otherwise.
         */
        virtual bool pollEvent(Event event) = 0;

        /**
         * @brief Displays the current window.
         */
        virtual void display() = 0;

        /**
         * @brief Opens the display window.
         * @return True if the window was opened, false otherwise.
         */
        virtual bool open() = 0;

        /**
         * @brief Closes the display window.
         */
        virtual void close() = 0;

        /**
         * @brief Clears the display window.
         */
        virtual void clear() = 0;

        /**
         * @brief Returns the last event polled from the display window.
         * @return The last event polled.
         */
        virtual arcade::Event useEvent() = 0;

        /**
         * @brief Draws a sprite to the display window.
         * @param sprite The sprite to draw.
         */
        virtual void draw(arcade::Sprite &sprite) = 0;

        /**
         * @brief Draws the background of the display window.
         */
        virtual void drawBack() = 0;

        /**
         * @brief Draws text to the display window.
         * @param text The text to draw.
         */
        virtual void drawText(arcade::Text &text) = 0;

        /**
         * @brief Returns the name of the graphical library being used.
         * @return The name of the graphical library.
         */
        virtual std::string graphicalName() const = 0;
    };

}

#endif /* !IDISPLAYMODULE_HPP_ */
