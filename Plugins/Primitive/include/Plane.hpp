/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Plane
*/

#include "IPrimitive.hpp"
#include "Material.hpp"
#include "Ray.hpp"
#include "myUtils.hpp"
#include <cmath>
#include <iostream>

class Plane : public IPrimitive
{
    private:
        sf::Vector3f m_position;
        sf::Vector3f m_normal;
        Material m_material;

    public:
        Plane();
        Plane(sf::Vector3f normal, sf::Vector3f position, Material &material);
        ~Plane() = default;

        float intersection(const Ray &ray) const final;

        sf::Color HitObject(const Ray &, const HitPayload &, const ILight &) const final;

        // getter
        sf::Vector3f getPosition() const;

        const Material &getMaterial() const final;

        // setter
        IPrimitive &setMaterial(Material) final;

        IPrimitive &setPosition(sf::Vector3f) final;

        IPrimitive &setNormal(sf::Vector3f) final;

        IPrimitive &setHeight(float) final;

        IPrimitive &setRadius(float) final;
};
