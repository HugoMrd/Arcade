/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-hugo.mouraud
** File description:
** Map
*/

#ifndef MAP_HPP_
    #define MAP_HPP_
    #include <vector>
    #include <iostream>
    #include <fstream>

namespace arcade {
    /**
     * @class Map
     * @brief Class representing the game map.
     */
    class Map {
        public:
            /**
             * @brief Constructs a Map object.
             */
            Map();

            /**
             * @brief Destroys the Map object.
             */
            ~Map() = default;

            /**
             * @brief Gets the game map.
             * @return A vector of strings representing the map.
             */
            std::vector<std::string> getMap(void);

            /**
             * @brief Opens the game map file and loads the map.
             * @param fileMap The path of the file containing the map.
             * @return True if the map was successfully loaded, false otherwise.
             */
            bool openMap(std::string fileMap);

        protected:
            std::vector<std::string> _map; /** A vector of strings representing the map. */
    };
}

#endif /* !MAP_HPP_ */
