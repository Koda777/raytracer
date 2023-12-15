/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PrimitiveFactory
*/

#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

/**
 * @brief An interface that represents a camera.
 *
 * This interface provides methods to calculate the direction of a ray for a given pixel, and to get and set the camera's
 * position, direction, and field of view.
 */
class ICamera
{
    public:
        /**
         * @brief Destructor.
         */
        virtual ~ICamera() = default;

        /**
         * @brief Calculates the direction of a ray for a given pixel.
         *
         * @param width The width of the image.
         * @param height The height of the image.
         */
        virtual void calculateRayDirection(int width, int height) = 0;

        // Getter

        /**
         * @brief Gets the direction of the ray for a given pixel.
         *
         * @param width The width of the image.
         * @param height The height of the image.
         * @return A pointer to a vector representing the direction of the ray.
         */
        virtual sf::Vector3f *getRayDirection(int width, int height) = 0;

        /**
         * @brief Gets the camera's position.
         *
         * @return A vector representing the camera's position.
         */
        virtual sf::Vector3f getCameraPosition() const = 0;

        /**
         * @brief Sets the camera's field of view.
         *
         * @param fov The new field of view.
         * @return A reference to the camera.
         */
        virtual ICamera &setFOV(float) = 0;

        /**
         * @brief Sets the camera's direction.
         *
         * @param direction The new direction.
         * @return A reference to the camera.
         */
        virtual ICamera &setDirection(sf::Vector3f) = 0;

        /**
         * @brief Sets the camera's position.
         *
         * @param position The new position.
         * @return A reference to the camera.
         */
        virtual ICamera &setPosition(sf::Vector3f) = 0;
};