/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-hugo.mouraud
** File description:
** Text
*/

#ifndef TEXT_HPP_
    #define TEXT_HPP_
    #include <string>
    #include <vector>
    #include "Color.hpp"

namespace arcade {
    /**
     * @class Text
     * @brief Class that represents a text object
     */
    class Text {
        public:

            /**
             * @brief Construct a new Text object
             *
             * @param text The text to be displayed
             * @param pos The position of the text
             * @param size The size of the text
             * @param color The color of the text
             */
            Text(const std::string &text, std::vector<float> pos, std::vector<float> size = {30}, arcade::Color color = {255, 255, 255, 255});

            /**
             * @brief Destroy the Text object
             */
            ~Text();

            /* draw our text */
            /**
             * @brief Draw the text on the screen
             */
            void draw();

            /*******/
            /* Position text */
            /**
             * @brief Set the position of the text
             *
             * @param pos The new position of the text
             */
            void setPosition(std::vector<float> pos);

            /**
             * @brief Get the position of the text
             *
             * @return The position of the text
             */
            std::vector<float> getPosition() const;

            /**
             * @brief Set the X coordinate of the text
             *
             * @param x The new X coordinate of the text
             */
            void setX(float x);

            /**
             * @brief Get the X coordinate of the text
             *
             * @return The X coordinate of the text
             */
            float getX(void);

            /**
             * @brief Set the Y coordinate of the text
             *
             * @param y The new Y coordinate of the text
             */
            void setY(float y);

            /**
             * @brief Get the Y coordinate of the text
             *
             * @return The Y coordinate of the text
             */
            float getY(void);

            /**
             * @brief Set the X coordinate of the text
             *
             * @param posX The new X coordinate of the text
             */
            void setPosX(float posX);

            /**
             * @brief Get the X coordinate of the text
             *
             * @return The X coordinate of the text
             */
            float getPosX(void);

            /**
             * @brief Set the Y coordinate of the text
             *
             * @param posY The new Y coordinate of the text
             */
            void setPosY(float posY);

            /**
             * @brief Get the Y coordinate of the text
             *
             * @return The Y coordinate of the text
             */
            float getPosY(void);

            /* Manage move text */
            /**
             * @brief Move the text by a certain amount
             *
             * @param x The amount to move the text along the X axis
             * @param y The amount to move the text along the Y axis
             */
            void move(float x, float y);

            /* Manage speed text */
            /**
             * @brief Set the speed of the text
             *
             * @param speed The new speed of the text
             */
            void setSpeed(float speed);

            /**
             * @brief Get the speed of the text
             *
             * @return The speed of the text
             */
            float getSpeed() const;

             /**
             * @brief Rotates the text by a given angle
             * @param angle The angle to rotate the text by
             */
            void rotate(float angle);

            /**
             * @brief Gets the angle of the text
             * @return The angle of the text
             */
            float getAngle() const;

            /**
             * @brief Sets the color of the text
             * @param color The color to set the text to
             */
            void setColor(Color color);

            /**
             * @brief Gets the color of the text
             * @return The color of the text
             */
            Color getColor() const;

            /**
             * @brief Sets the font of the text
             * @param font The name of the font to set the text to
             */
            void setFont(const std::string &font);

            /**
             * @brief Loads the font of the text
             * @return The name of the font used by the text
             */
            std::string loadFont() const;

            /**
             * @brief Sets the text of the text object
             * @param text The text to set
             */
            void setText(const std::string &text);

            /**
             * @brief Gets the text of the text object
             * @return The text of the text object
             */
            std::string getText() const;

            /**
             * @brief Sets the size of the text object
             * @param size A vector containing the size of the text
             */
            void setSize(std::vector<float> size);

            /**
             * @brief Gets the size of the text object
             * @return A vector containing the size of the text object
             */
            std::vector<float> getSize() const;

        private:
            std::string _text; /**< The text */
            std::vector<float> _pos; /**< The position of the text */
            std::vector<float> _size; /**< The size of the text */
            Color _color; /**< The color of the text */
            float _x; /**< The x-coordinate of the text */
            float _y; /**< The y-coordinate of the text */
    };
}

#endif /* !TEXT_HPP_ */
