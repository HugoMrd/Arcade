/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-hugo.mouraud
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
    #define PACMAN_HPP_
    #include <memory>
    #include <vector>
    #include <iostream>
    #include <unordered_map>
    #include <chrono>
    #include <algorithm>
    #include <random>
    #include "../../../src/Core/Map.hpp"
    #include "../../../src/Window/Text.hpp"
    #include "../../IGameModule.hpp"

namespace arcade {
    /**
     * @class Pacman
     * @brief Game module representing the classic Pacman game.
     */
    class Pacman : public IGameModule {
        public:
            /**
             * @brief Default constructor for Pacman.
             */
            Pacman();
            /**
             * @brief Destructor for Pacman.
             */
            ~Pacman() override;
            /**
             * @brief Handles the event of the game module.
             * @param event the event to handle
             */
            void event(Event event) override;
            /**
             * @brief Loads the high score of the game module.
             */
            void loadHighScore() override;
            /**
             * @brief Updates the score of the game module.
             */
            void updateScore() override;
            /**
             * @brief Returns the score of the game module.
             * @return the score of the game module
             */
            int getScore() override;
            /**
             * @brief Quits the game module.
             */
            void quit() override;
            /**
             * @brief Resumes the game module.
             */
            void resume() override;
            /**
             * @brief Changes the speed of the player according to the input keys.
             * @param keys the keys to read
             */
            void speedPlayer(Event keys) override;
            /**
             * @brief Handles the pause option of the game module.
             * @param graphical the display module
             * @param keys the keys to read
             */
            void pause(IDisplayModule &graphical, Event keys) override;
            /**
             * @brief Returns whether the game module is paused or not.
             * @return true if the game module is paused, false otherwise
             */
            bool isPaused() override;
            /**
             * @brief Sets the move of the player according to the input keys.
             * @param graphical the display module
             */
            void setMovePlayer(IDisplayModule &graphical) override;
            /**
             * @brief Runs the game module.
             * @param graphicLib the display module
             */
            void run(IDisplayModule &graphicLib) override;
            /**
             * @brief Initializes the Pacman game.
             */
            void initMap(void);
            void initScore(void);
            void initGhost(void);
            void initClock(void);
            /**
             * @brief Prints the ghosts on the display module.
             * @param graphicLib the display module
             */
            void printGhost(IDisplayModule &graphicLib);
            /**
             * @brief Moves the ghosts.
             */
            void ghostMove(void);

            /**
             * @brief Checks if a position is valid on the map.
             * @param x the x coordinate
             * @param y the y coordinate
             * @return true if the position is valid, false otherwise
             */
            bool isValidPosition(float x, float y);

            /**
             * @brief Moves the player according to the input keys.
             * @param keys the keys to read
             */
            void pacmanMove(arcade::Event keys);

            /**
             * @brief Prints the map on the display module.
             * @param graphicLib the display module
             */
            void printMap(IDisplayModule &graphicLib);

            /**
             * @brief Dessine un rectangle de couleur donnée à la position spécifiée.
             * @param y La coordonnée y de la position où dessiner le rectangle.
             * @param x La coordonnée x de la position où dessiner le rectangle.
             * @param graphical Le module graphique utilisé pour le dessin.
             * @param color La couleur du rectangle.
             */
            void drawRectangle(float y, float x, IDisplayModule &graphical, Color color);
            /**
             * @brief Dessine un rectangle de couleur donnée à la position spécifiée.
             * @param y La coordonnée y de la position où dessiner le rectangle.
             * @param x La coordonnée x de la position où dessiner le rectangle.
             * @param graphical Le module graphique utilisé pour le dessin.
             * @param color La couleur du rectangle.
             */
            void drawFood(float y, float x, IDisplayModule &graphical, Color color, bool bonus);
            /**
             * @brief Réinitialise les données du jeu pour recommencer une nouvelle partie.
            */
            void restart() override;

        /**
            @brief Class attributes for the Pacman game module.
            This class contains all the necessary attributes for the Pacman game module, including the game state,
            positions of player and ghosts, pointers to game objects, maps and the score, etc.
            @note The member variables are protected for inheritance and encapsulation purposes. The private
            variables are for internal use only and are not accessible from outside the class.
        */
        protected:
            Event _keys; /**< The current state of the keyboard input*/
		    std::chrono::steady_clock::time_point _time; /**<The current time of the game */
		    float _slow; /**<The current time slow rate of the game*/
	        arcade::Event _useKeys; /**<The event for the keys used in the game*/
		    std::vector<float> _posPlayer; /**< The position of the player*/
		    std::vector<std::pair<float, float>> _posGhost; /**<The position of the ghosts */
            std::unique_ptr<Map> _map; /**< The pointer to the game map*/
            std::unique_ptr<arcade::Text> _text; /**<The pointer to the game score text */
            std::unique_ptr<arcade::Text> _defaultSpeed; /**<The pointer to the default speed text*/
            std::vector<std::string> _pacmanMap;/**< The Pacman game map*/
            std::vector<float> _sizeMap; /**<The size of the Pacman game map*/
            int _score; /**<The current score of the game*/
            int _speed; /**<The current speed of the game*/
        private:
            std::vector<arcade::Color> _colorGhost = { /**< The map for moving left and right*/
                {255, 0, 0, 255},
                {5, 244, 71,  255},
                {30, 0, 255, 255},
                {255, 184, 222, 255}
	        };
            std::unordered_map<arcade::Event, float> _leftAndRight = { /**<The map for moving left and right*/
                {up, 0},
                {down, 0},
                {left, -1},
                {right, 1},
            };
            std::unordered_map<arcade::Event, float> _upAndDown = { /**<The map for moving up and down*/
                {up, -1},
                {down, 1},
                {left, 0},
                {right, 0},
            };
    };
}

#endif /* !PACMAN_HPP_ */
