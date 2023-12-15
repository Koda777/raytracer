/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Cylinder
*/

#include "IPrimitive.hpp"
#include "Material.hpp"
#include "Ray.hpp"
#include "myUtils.hpp"
#include <cmath>
#include <iostream>

class LimitedCylinder : public IPrimitive
{
    private:
        float m_radius;
        sf::Vector3f m_position;
        float m_height;
        Material m_material;

    public:
        LimitedCylinder();
        LimitedCylinder(float radius, sf::Vector3f position, float height, Material &material);
        ~LimitedCylinder() = default;

        float intersection(const Ray &ray) const final;

        sf::Color HitObject(const Ray &, const HitPayload &, const ILight &) const final;

        // getter
        sf::Vector3f getPosition() const final;

        const Material &getMaterial() const final;

        // builder
        IPrimitive &setMaterial(Material) final;

        IPrimitive &setPosition(sf::Vector3f) final;

        IPrimitive &setNormal(sf::Vector3f) final;

        IPrimitive &setHeight(float) final;

        IPrimitive &setRadius(float) final;
};
