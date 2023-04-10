/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-hugo.mouraud
** File description:
** GameLoader
*/

#ifndef GAMELOADER_HPP_
    #define GAMELOADER_HPP_
    #include <iostream>
    #include <regex>
    #include <fstream>
    #include <dlfcn.h>
    #include "../../Games/IGameModule.hpp"
    #include "../Error/Error.hpp"

/**
 * @namespace arcade
 * @brief Namespace containing all the classes and functions related to the arcade project
*/
namespace arcade {
    /**
    * @brief Class handling the loading and unloading of game libraries
    */
    class GameLoader {
        public:
            /**
            * @brief Construct a new GameLoader object
            */
            GameLoader();
             /**
             * @brief Destroy the GameLoader object
             */
            ~GameLoader();
            /**
             * @brief Check if a game library exists at the specified path
             * @param path Path to the game library
             * @return True if the game library exists, false otherwise
             */
            bool checkGame(const std::string &path);
            /**
             * @brief Load the specified game library
             * @param path Path to the game library
             * @return True if the game library was successfully loaded, false otherwise
             */
            bool Game(const std::string &path);
            /**
             * @brief Get a pointer to the currently loaded game
             * @return Pointer to the IGameModule interface of the loaded game, or nullptr if no game is loaded
             */
            IGameModule *getGame(void);
            /**
             * @brief Unload the currently loaded game library
             */
            void destroyGame(void);
        protected:
            std::string _path;
            IGameModule *_game;
            void *_openGame;
    };
}

#endif /* !GAMELOADER_HPP_ */
