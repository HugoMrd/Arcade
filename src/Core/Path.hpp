/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-hugo.mouraud
** File description:
** Path
*/

#ifndef PATH_HPP_
    #define PATH_HPP_
    #include <fstream>

/**
 * @namespace arcade
 * @brief Namespace that contains all the classes and functions of the arcade project
 */
namespace arcade {
    /**
     * @class Path
     * @brief Class that handles checking the validity of a file path
     */
    class Path {
        public:
            /**
             * @brief Destructor of Path class
             */
            ~Path() = default;
            /**
             * @brief Method that checks the validity of a file path
             * @param av The argument of the file path
             * @return true if the file path is valid, false otherwise
             */
            bool pathFile(char **av);
    };
}

#endif /* !PATH_HPP_ */
