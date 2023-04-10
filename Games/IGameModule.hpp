/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-hugo.mouraud
** File description:
** IGameModule
*/

#ifndef IGAMEMODULE_HPP_
#define IGAMEMODULE_HPP_

#include "../src/Window/IDisplayModule.hpp"
#include "../src/System/Event.hpp"

namespace arcade {

    /**
     * @brief The IGameModule class is an abstract class that represents a game module. It contains pure virtual functions for handling events, managing scores, pausing the game, controlling the player's movement, and running the game loop.
     */
    class IGameModule {

        public:

            /**
             * @brief Destroy the IGameModule object.
             */
            virtual ~IGameModule() = default;

            /**
             * @brief Handle an event that occurred in the game.
             * @param event The event that occurred.
             */
            virtual void event(Event event) = 0;

            /**
             * @brief Load the high score for the current game.
             */
            virtual void loadHighScore() = 0;

            /**
             * @brief Update the score of the current game.
             */
            virtual void updateScore() = 0;

            /**
             * @brief Get the score of the current game.
             * @return The score of the current game.
             */
            virtual int getScore() = 0;

            /**
             * @brief Quit the game.
             */
            virtual void quit() = 0;

            /**
             * @brief Resume the game.
             */
            virtual void resume() = 0;

            /**
             * @brief Change the player's speed based on the keys that were pressed.
             * @param keys The keys that were pressed.
             */
            virtual void speedPlayer(Event keys) = 0;

            /**
             * @brief Pause the game.
             * @param graphical The display module to use for pausing.
             * @param keys The keys that were pressed.
             */
            virtual void pause(IDisplayModule &graphical, Event keys) = 0;

            /**
             * @brief Check if the game is paused.
             * @return true if the game is paused, false otherwise.
             */
            virtual bool isPaused() = 0;

            /**
             * @brief Set the player's movement in the display module.
             * @param graphical The display module to use for setting the player's movement.
             */
            virtual void setMovePlayer(IDisplayModule &graphical) = 0;

            /**
             * @brief Run the game loop.
             * @param graphicLib The display module to use for running the game loop.
             */
            virtual void run(IDisplayModule &graphicLib) = 0;

            /**
             * @brief Restart the game.
             */
            virtual void restart() = 0;
    };
};

#endif /* !IGAMEMODULE_HPP_ */
