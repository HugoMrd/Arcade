/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-hugo.mouraud
** File description:
** Sprite
*/

#ifndef SPRITE_HPP_
    #define SPRITE_HPP_

    #include <vector>
    #include <string>
    #include "Color.hpp"

namespace arcade {
    /**
     * @class Sprite
     * @brief Class representing a sprite
     */
    class Sprite {
        public:

            /**
             * @brief Constructor for the Sprite class
             * @param size The size of the sprite
             * @param pos The position of the sprite
             * @param color The color of the sprite
             */
            Sprite(std::vector<float> size = {}, std::vector<float> pos = {}, arcade::Color color = {0, 244, 244, 244});

            /**
             * @brief Destructor for the Sprite class
             */
            ~Sprite() = default;

            /**
             * @brief Sets the position of the sprite
             * @param pos The new position of the sprite
             */
            void setPosition(std::vector<float> pos);

            /**
             * @brief Gets the position of the sprite
             * @return The position of the sprite
             */
            std::vector<float> getPosition() const;

            /**
             * @brief Draws the sprite
             */
            void draw();

            /**
             * @brief Sets the size of the sprite
             * @param size The new size of the sprite
             */
            void setSize(std::vector<float> size);

            /**
             * @brief Gets the size of the sprite
             * @return The size of the sprite
             */
            std::vector<float> getSize() const;

            /**
             * @brief Gets the height of the sprite
             * @return The height of the sprite
             */
            float getH() const;

            /**
             * @brief Gets the y-coordinate of the sprite
             * @return The y-coordinate of the sprite
             */
            float getY() const;

            /**
             * @brief Sets the height of the sprite
             * @param height The new height of the sprite
             */
            void setH(float height);

            /**
             * @brief Sets the y-coordinate of the sprite
             * @param y The new y-coordinate of the sprite
             */
            void setY(float y);

            /**
             * @brief Gets the width of the sprite
             * @return The width of the sprite
             */
            float getW() const;

            /**
             * @brief Gets the x-coordinate of the sprite
             * @return The x-coordinate of the sprite
             */
            float getX() const;

            /**
             * @brief Sets the width of the sprite
             * @param width The new width of the sprite
             */
            void setW(float width);

            /**
             * @brief Sets the x-coordinate of the sprite
             * @param x The new x-coordinate of the sprite
             */
            void setX(float x);

            /**
             * @brief Sets the sprite using an image
             * @param pos The position of the sprite
             * @param size The size of the sprite
             * @param image The name of the image file to use for the sprite
             */
            void setSprite(std::vector<float> pos, std::vector<float> size, std::string image);

            /**
             * @brief Moves the sprite by a given amount
             * @param x The amount to move the sprite in the x-direction
             * @param y The amount to move the sprite in the y-direction
             */
            void move(float x, float y);
            /**
             * @brief Sets the speed of the sprite.
             *
             * @param speed The speed to set.
             */
            void setSpeed(float speed);

            /**
             * @brief Gets the speed of the sprite.
             *
             * @return The sprite's speed.
             */
            float getSpeed() const;

            /**
             * @brief Rotates the sprite.
             *
             * @param angle The angle to rotate the sprite by.
             */
            void rotate(float angle);

            /**
             * @brief Gets the current angle of the sprite.
             *
             * @return The angle of the sprite.
             */
            float getAngle() const;

            /**
             * @brief Sets the sprite color at a specific position.
             *
             * @param pos The position to set the sprite at.
             * @param col The color to set the sprite to.
             */
            void setSprite(std::vector<float> pos, Color col);

            /**
             * @brief Gets the sprite color at a specific position.
             *
             * @param pos The position to get the sprite from.
             * @return The color of the sprite.
             */
            Color getSprite(std::vector<float> pos) const;

            /**
             * @brief Gets the sprite array.
             *
             * @return A reference to the sprite array.
             */
            std::vector<Color> &getSpriteArray();

        private:
            std::vector<float> _size; /**< The size of the sprite. */
            std::vector<float> _pos; /**< The position of the sprite. */
            std::vector<Color> _color; /**< The color of the sprite. */
    };
};

#endif /* !SPRITE_HPP_ */
