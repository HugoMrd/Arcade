/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-hugo.mouraud
** File description:
** Name
*/

#ifndef NAME_HPP_
    #define NAME_HPP_
    #define SIZENAME 21
    #include <iostream>
    #include <fstream>
    #include <map>
    #include "../Window/IDisplayModule.hpp"

/**
 * @namespace arcade
 * @brief Namespace for arcade project
 */
namespace arcade {
    /**
     * @class Name
     * @brief Class representing a player name and their score
     */
    class Name {
        public:
            /**
             * @brief Default constructor for Name class
             */
            Name();
            /**
             * @brief Default destructor for Name class
             */
            ~Name() = default;

            /**
             * @brief Method to print the name of the player
             * @param keys Event to handle player inputs
             */
            void printName(arcade::Event keys);
            /**
             * @brief Method to create a player name and save their score
             * @param graphical Display module for graphical interaction
             * @return int representing the score of the player
             */
            int createName(IDisplayModule &graphical);
            /**
             * @brief Method to write the score to a file
             */
            void writeScore(void);
            /**
             * @brief Method to set the score of the player
             * @param score int representing the score of the player
             */
            void setScore(int score);
        protected:
            std::string _namePlayer;
        	std::string _input;
            std::multimap<int, std::string> _nameScore;
            int _score;
    };
}

#endif /* !NAME_HPP_ */
