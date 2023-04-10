/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-hugo.mouraud
** File description:
** Snake
*/

#ifndef SNAKE_HPP_
    #define SNAKE_HPP_
    #include <memory>
    #include <vector>
    #include <random>
    #include <chrono>
    #include "../../../src/Core/Map.hpp"
    #include "../../../src/Core/Score.hpp"
    #include "../../../src/Window/Text.hpp"
    #include "../../../src/Window/IDisplayModule.hpp"
    #include "../../IGameModule.hpp"

namespace arcade {
    /**
     * @class Snake
     * @brief This class represents the game of Snake
     */
    class Snake : public IGameModule {
        public:
            /**
             * @brief Construct a new Snake object
             */
            Snake();
            /**
             * @brief Destroy the Snake object
             */
            ~Snake() override;
            /**
             * @brief Spawns food at a random position on the map
             * @return true if food was successfully spawned, false otherwise
             */
            bool spawnFood(void);
            /**
             * @brief Moves the snake
             * @param keys event keys pressed
             * @param graphical graphical module to display the game
             */
            void snakeMove(Event keys, IDisplayModule &graphical);
            /**
             * @brief Initializes the keys of the game
             * @param keys event keys pressed
             */
            void initKeys(Event keys);
            /**
             * @brief Initializes the player
             */
            void initPlayer(void);
            /**
             * @brief Initializes the map
             */
            void initMap(void);
            /**
             * @brief Initializes the score
             */
            void initScore(void);
            /**
             * @brief Initializes the clock
             */
            void initClock(void);
            /**
             * @brief Receives and handles events
             * @param event the event to handle
             */
            void event(Event) override;
            /**
             * @brief Loads the high score from file
             */
            void loadHighScore() override;
            /**
             * @brief Updates the score
             */
            void updateScore() override;
            /**
             * @brief Returns the current score
             * @return the score
             */
            int getScore() override;
            /**
             * @brief Quits the game
             */
            void quit() override;
            /**
             * @brief Resumes the game from pause
             */
            void resume() override;
            /**
             * @brief Changes the speed of the player
             * @param keys event keys pressed
             */
            void speedPlayer(Event keys) override;
            /**
             * @brief Pauses the game
             * @param graphical graphical module to display the game
             * @param keys event keys pressed
             */
            void pause(IDisplayModule &graphical, Event keys) override;
            /**
             * @brief Checks if the game is paused
             * @return true if the game is paused, false otherwise
             */
            bool isPaused() override;
            /**
             * @brief Draws a rectangle on the screen
             * @param y the y coordinate of the rectangle
             * @param x the x coordinate of the rectangle
             * @param graphical graphical module to display the game
             * @param color color of the rectangle
             */
            void drawRectangle(float y, float x, IDisplayModule &graphical, Color color);
            /**
             * @brief Prints the player on the screen
             * @param graphical graphical module to display the game
             */
            void printPlayer(IDisplayModule &graphical);
            /**
             * @brief Prints the map on the screen
             * This function takes a graphical object as an argument and uses it to print the map on the screen.
             * @param graphical the IDisplayModule object used to print on the screen
             */
            void printMap(IDisplayModule &graphical);

            /**
             * @brief Determines whether the player has eaten food or not
             * This function takes the player's input keys as an argument and determines whether the player has eaten
             * food or not.
             * @param keys the input keys provided by the player
             * @return 1 if the player has eaten food, 0 otherwise
             */
            int eatFood(Event keys);

            /**
             * @brief Determines whether the game has ended or not
             * This function determines whether the game has ended or not.
             * @return true if the game has ended, false otherwise
             */
            bool endSnake(void);

            /**
             * @brief Determines the player's position
             * This function determines the player's position and sets it accordingly.
             */
            void posPlayer(void);

            /**
             * @brief Determines whether the player has gone backwards
             * This function takes the player's input keys as an argument and determines whether the player has gone
             * backwards or not.
             * @param keys the input keys provided by the player
             * @return true if the player has gone backwards, false otherwise
             */
            bool snakeBack(Event keys);

            /**
             * @brief Sets the player's movement
             * This function takes a graphical object as an argument and sets the player's movement.
             * @param graphical the IDisplayModule object used to print on the screen
             */
            void setMovePlayer(IDisplayModule &graphical) override;

            /**
             * @brief Runs the game
             * This function takes a graphical object as an argument and runs the game.
             * @param graphical the IDisplayModule object used to print on the screen
             */
            void run(IDisplayModule &graphical) override;
            void restart() override;

        protected:
            Event _keys; /**< The current state of the keyboard input*/
	        arcade::Event _useKeys; /**<The event for the keys used in the game*/
            std::chrono::steady_clock::time_point _time; /**<The current time of the game */
		    float _slow; /**<The current time slow rate of the game*/
            int _score; /**<The current score of the game*/
            int _speed; /**<The current speed of the game*/
            std::unique_ptr<Map> _map; /**< The pointer to the game map*/
            std::unique_ptr<Score> _printScore; /**< The pointer to the score printing*/
            IDisplayModule *_graphical;
            std::unique_ptr<arcade::Text> _text; /**<The pointer to the game score text */
            std::unique_ptr<arcade::Text> _defaultSpeed; /**<The pointer to the default speed text*/
            std::vector<std::string> _snakeMap; /**< The snake game map*/
            std::vector<std::pair<float, float>> _posPlayer; /**< The position of the player*/
            std::vector<float> _posFood; /**< The position of the food in game*/
        private:
    };
}

#endif /* !SNAKE_HPP_ */
