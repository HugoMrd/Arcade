/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-hugo.mouraud
** File description:
** Score
*/

#ifndef SCORE_HPP_
    #define SCORE_HPP_
    #include <unordered_map>
    #include <exception>
    #include <regex>
    #include <iostream>
    #include <fstream>
    #include "../Window/Text.hpp"
    #include "../Error/Error.hpp"
    #include "../System/Event.hpp"
    #include "../Window/IDisplayModule.hpp"

namespace arcade {
    /**
     * @brief The Score class manages game scores
     */
    class Score {
        public:
            /**
             * @brief Construct a new Score object
             *
             */
            Score();
            /**
             * @brief Destroy the Score object
             *
             */
            ~Score() = default;
            /**
             * @brief Initializes the score data
             *
             * @param graphical The graphical module where the scores will be displayed
             */
		    void initScore(IDisplayModule &graphical);
            /**
             * @brief Displays the scores
             *
             * @param graphical The graphical module where the scores will be displayed
             */
		    void drawScore(IDisplayModule &graphical);

        protected:
        	std::unordered_map<float, std::string> _score;
    };
}

#endif /* !SCORE_HPP_ */
