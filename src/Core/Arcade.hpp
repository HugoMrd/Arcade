/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-hugo.mouraud
** File description:
** Arcade
*/

#ifndef ARCADE_HPP_
    #define ARCADE_HPP_
    #include <vector>
    #include <algorithm>
    #include <future>
    #include "GraphicalLoader.hpp"
    #include "GameLoader.hpp"
    #include "Menu.hpp"
    #include "Name.hpp"
    #include "Score.hpp"
    #include "../Window/IDisplayModule.hpp"
    #include "../../Games/IGameModule.hpp"
    #include "../System/Event.hpp"

/**
 * Namespace for the arcade project
 */
namespace arcade {
    /**
     * @class Arcade
     * @brief Arcade class that manages the menu and the game
     */
    class Arcade {
        public:
            /**
             * Constructor
             * @param path The path to the configuration file
             */
            Arcade(const std::string &path);

            /**
             * Destructor
             */
            ~Arcade() = default;

            /**
             * Check if the game is loaded
             * @return True if the game is loaded, false otherwise
             */
            bool checkGame(void);

            /**
             * Check if the graphical library is loaded
             * @return True if the graphical library is loaded, false otherwise
             */
            bool checkGraphical(void);

            /**
             * Check if the menu is loaded
             * @return True if the menu is loaded, false otherwise
             */
            bool checkMenu(void);

            /**
             * Run the menu
             * @return 0 on success, -1 on failure
             */
            bool runMenu();

            /**
             * Run the game
             * @return 0 on success, -1 on failure
             */
            int run(void);

            /**
             * Loading arcade menu
             * @param keys The event to handle
             * @return 0 on success, -1 on failure
             */
            int loadingArcade(Event keys);

            /**
             * Restart the game
             * @param keys The event to handle
             */
            void restartGame(Event keys);

            /**
             * Switch the game
             * @param keys The event to handle
             */
            void switchGame(Event keys);

            /**
             * Switch the graphical library
             * @param keys The event to handle
             */
            void switchGraphical(Event keys);

        protected:
            GameLoader _gameLoader; /** The game loader */
            GraphicalLoader _graphicalLoader; /** The graphical loader */
            std::vector<std::string> _gameLister; /** The list of games */
            std::vector<std::string> _graphicalLister; /** The list of graphical libraries */
            std::size_t _listGame; /** The current selected game */
            std::size_t _listGraphical; /** The current selected graphical library */
            IGameModule *_game; /** The game */
            IDisplayModule *_graphical; /** The graphical library */
            std::unique_ptr<Menu> _menu; /** The menu */
            std::unique_ptr<Name> _namePlayer; /** The player name */
            std::unique_ptr<Score> _score; /** The score */
            std::string _check; /** The check */
    };
}

#endif /* !ARCADE_HPP_ */
