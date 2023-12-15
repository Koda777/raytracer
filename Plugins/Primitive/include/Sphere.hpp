/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Sphere
*/

#include "IPrimitive.hpp"
#include "Material.hpp"
#include "Ray.hpp"
#include "myUtils.hpp"
#include <cmath>
#include <iostream>

class Sphere : public IPrimitive
{
    private:
        float m_radius;
        sf::Vector3f m_position;
        Material m_material;

    public:
        Sphere();
        Sphere(float, sf::Vector3f, Material &);
        ~Sphere() = default;

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