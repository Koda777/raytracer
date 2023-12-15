/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ILight
*/

#pragma once
#include <SFML/Graphics.hpp>

/**
 * @brief An interface that represents a light source.
 *
 * This interface provides methods to get and set the position and intensity of the light source.
 */
class ILight
{
    public:
        /**
         * @brief Destructor.
         */
        virtual ~ILight() = default;

        /**
         * @brief Gets the position of the light source.
         *
         * @return A vector representing the position of the light source.
         */
        virtual sf::Vector3f getPosition() const = 0;

        /**
         * @brief Gets the intensity of the light source.
         *
         * @return The intensity of the light source.
         */
        virtual float getIntensity() const = 0;

        /**
         * @brief Sets the position of the light
         *
         * @param position New position of the light
         * @return ILight& Reference to the modified ILight object
         */
        virtual ILight &setPosition(const sf::Vector3f position) = 0;

        /**
         * @brief Sets the intensity of the light
         *
         * @param intensity New intensity of the light
         * @return ILight& Reference to the modified ILight object
         */
        virtual ILight &setIntensity(float intensity) = 0;
};
