/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-hugo.mouraud
** File description:
** GraphicalLoader
*/

#ifndef GRAPHICALLOADER_HPP_
    #define GRAPHICALLOADER_HPP_
    #include <iostream>
    #include <regex>
    #include <fstream>
    #include <dlfcn.h>
    #include "../Window/IDisplayModule.hpp"
    #include "../Error/Error.hpp"

namespace arcade {
    /**
     * @class GraphicalLoader
     * @brief Handles the loading of graphical libraries
     */
    class GraphicalLoader {
        public:
            /**
             * @brief Constructor of GraphicalLoader class
             */
            GraphicalLoader();

            /**
             * @brief Destructor of GraphicalLoader class
             */
            ~GraphicalLoader();

            /**
             * @brief Checks if the graphical library is available
             * @param path The path to the graphical library
             * @return true if the library is available, false otherwise
             */
            bool checkGraphical(const std::string &path);

            /**
             * @brief Loads the graphical library
             * @param path The path to the graphical library
             * @return true if the library was loaded successfully, false otherwise
             */
            bool Graphical(const std::string &path);

            /**
             * @brief Returns the loaded graphical library
             * @return a pointer to the loaded graphical library
             */
            IDisplayModule *getGraphical(void);

            /**
             * @brief Destroys the loaded graphical library
             */
            void destroyGraphical(void);

        protected:
            std::string _path; /** The path to the graphical library */
            IDisplayModule *_graphical; /** A pointer to the loaded graphical library */
            void *_openGraphical; /** A pointer to the handle of the loaded graphical library */
    };
}

#endif /* !GRAPHICALLOADER_HPP_ */
