/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** IPrimitive
*/

#include "HitPayload.hpp"
#include "ILight.hpp"
#include "Material.hpp"
#include "Ray.hpp"
#include <SFML/Graphics.hpp>

#pragma once

/**
 * @brief  primitive objects in the raytracer scene.
 *
 * This interface provides methods to get and set the position and intensity of a primitive.
 */
class IPrimitive
{
    public:
        /**
         * @brief Destructor.
         */
        ~IPrimitive() = default;

        /**
         * @brief Calculates the intersection of a ray with the primitive object.
         *
         * @param ray The ray to intersect with the primitive object.
         *
         * @return The distance between the ray origin and the point of intersection with the primitive object.
         */
        virtual float intersection(const Ray &) const = 0;

        /**
         * @brief Calculates the color of a point of intersection with the primitive object.
         *
         * @param ray The ray that intersects the primitive object.
         * @param hitPayload A HitPayload object containing information about the intersection point.
         * @param light A pointer to the light source to use when calculating the color.
         *
         * @return The color of the primitive object at the intersection point.
         */
        virtual sf::Color HitObject(const Ray &, const HitPayload &, const ILight &) const = 0;

        // getter
        /**
         * @brief Gets the position of the primitive object.
         *
         * @return A sf::Vector3f object representing the position of the primitive object.
         */
        virtual sf::Vector3f getPosition() const = 0;

        /**
         * @brief Gets the material of the primitive object.
         *
         * @return A const Material& object representing the material of the primitive object.
         */
        virtual const Material &getMaterial() const = 0;

        // builder
        /**
         * @brief Sets the material of the primitive object.
         *
         * @param material The material to set for the primitive object.
         *
         * @return A reference to the modified IPrimitive object.
         */
        virtual IPrimitive &setMaterial(Material) = 0;

        /**
         * @brief Sets the position of the primitive object.
         *
         * @param position A sf::Vector3f object representing the position to set for the primitive object.
         *
         * @return A reference to the modified IPrimitive object.
         */
        virtual IPrimitive &setPosition(sf::Vector3f) = 0;

        /**
         * @brief Sets the normal vector of the primitive object.
         *
         * @param normal A sf::Vector3f object representing the normal vector to set for the primitive object.
         *
         * @return A reference to the modified IPrimitive object.
         */
        virtual IPrimitive &setNormal(sf::Vector3f) = 0;

        /**
         * @brief Sets the size of the primitive object.
         *
         * @param size The size to set for the primitive object.
         *
         * @return A reference to the modified IPrimitive object.
         */
        virtual IPrimitive &setHeight(float) = 0;

        /**
         * @brief Sets the size of the primitive object.
         *
         * @param size The size to set for the primitive object.
         *
         * @return A reference to the modified IPrimitive object.
         */
        virtual IPrimitive &setRadius(float) = 0;
};
