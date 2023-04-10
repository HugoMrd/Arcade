/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-hugo.mouraud
** File description:
** Menu
*/

#ifndef MENU_HPP_
    #define MENU_HPP_
    #include <iostream>
    #include <vector>
    #include <dirent.h>
    #include <regex>
    #include "../Window/IDisplayModule.hpp"
    #include "../System/Event.hpp"

namespace arcade {
    /**
     * @class Menu
     * @brief Cette classe gère les menus de sélection de jeux et d'interfaces graphiques dans l'application arcade.
     */
    class Menu {
        public:
            /**
             * Constructeur de la classe Menu.
             */
            Menu();

            /**
             * Charge la liste des jeux disponibles.
             *
             * @param gameLister une référence à un vecteur de chaînes de caractères contenant la liste des jeux disponibles.
             */
            void loadGameMenu(std::vector<std::string> &gameLister);

            /**
             * Charge la liste des librairies graphiques disponibles.
             *
             * @param graphicalLister une référence à un vecteur de chaînes de caractères contenant la liste des librairies graphiques disponibles.
             */
            void loadGraphicalMenu(std::vector<std::string> &graphicalLister);

            /**
             * Effectue le mouvement de la sélection du menu.
             *
             * @return true si le mouvement a été effectué, false sinon.
             */
            bool setupMove(void);

            /**
             * Bouge la sélection du menu en fonction des touches pressées.
             *
             * @param keys un objet Event contenant les touches pressées.
             */
            void moveMenu(arcade::Event keys);

            /**
             * Définit la liste des jeux disponibles.
             *
             * @param gameLister un vecteur de chaînes de caractères contenant la liste des jeux disponibles.
             */
            void setGameMenu(std::vector<std::string> gameLister);

            /**
             * Définit la liste des librairies graphiques disponibles.
             *
             * @param graphicalLister un vecteur de chaînes de caractères contenant la liste des librairies graphiques disponibles.
             */
            void setGraphicalMenu(std::vector<std::string> graphicalLister);

            /**
             * Affiche le menu de sélection des jeux avec le module graphique spécifié.
             *
             * @param game un objet IDisplayModule contenant le module graphique à utiliser pour l'affichage.
             * @param pos une référence à un vecteur de flottants contenant les coordonnées de la position du curseur de la souris.
             */
            void printGameMenu(arcade::IDisplayModule &game, std::vector<float> pos);

            /**
             * Affiche le menu de sélection des librairies graphiques avec le module graphique spécifié.
             *
             * @param graphical un objet IDisplayModule contenant le module graphique à utiliser pour l'affichage.
             * @param pos une référence à un vecteur de flottants contenant les coordonnées de la position du curseur de la souris.
             */
            void printGraphicalMenu(arcade::IDisplayModule &graphical, std::vector<float> pos);

            /**
             * Ouvre le menu de sélection et renvoie le nom du jeu sélectionné.
             *
             * @param graphLib un objet IDisplayModule contenant la librairie graphique à utiliser pour l'affichage.
             * @return une chaîne de caractères contenant le nom du jeu sélectionné.
             */
            std::string openMenu(IDisplayModule &graphLib);
        protected:
            std::vector<std::string> _gameLister;
            std::vector<std::string> _graphicalLister;
            std::pair<int, int> _cursorMouse;
    };
}

#endif /* !MENU_HPP_ */
