/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Plane
*/

#include "Plane.hpp"

Plane::Plane() : m_position{sf::Vector3f(0.0f, 0.0f, 0.0f)}, m_normal{sf::Vector3f(0.0f, 0.0f, 0.0f)}, m_material{Material()} {};

Plane::Plane(sf::Vector3f position, sf::Vector3f normal, Material &material) : m_position{position}, m_normal{normal}, m_material{material} {};

float Plane::intersection(const Ray &ray) const
{
    float denom = Vector3D::dot(m_normal, ray.direction);

    if (std::abs(denom) > 1e-6) {
        sf::Vector3f v = m_position - ray.origin;
        float t = Vector3D::dot(v, m_normal) / denom;

        if (t >= 0)
            return t;
    }
    return -1;
}

sf::Color Plane::HitObject(const Ray &ray, const HitPayload &payload, const ILight &light) const
{
    sf::Vector3f lightPoint = light.getPosition();

    sf::Vector3f planeOrigin = ray.origin - m_position;
    sf::Vector3f intersectionPoint = planeOrigin + (ray.direction * payload.hitDistance);

    // diffuse reflection color
    sf::Vector3f lightDirection = Vector3D::normalize(lightPoint - intersectionPoint);
    float lightIntensity = std::max(0.0f, Vector3D::dot(m_normal, -lightDirection));
    sf::Color color = m_material.albedo * lightIntensity;
    return color;
}

sf::Vector3f Plane::getPosition() const
{
    return m_position;
}

const Material &Plane::getMaterial() const
{
    return m_material;
}

IPrimitive &Plane::setMaterial(Material material)
{
    m_material = material;
    return *this;
}

IPrimitive &Plane::setPosition(sf::Vector3f position)
{
    m_position = position;
    return *this;
}

IPrimitive &Plane::setNormal(sf::Vector3f normal)
{
    m_normal = normal;
    return *this;
}

IPrimitive &Plane::setHeight(float)
{
    return *this;
}

IPrimitive &Plane::setRadius(float)
{
    return *this;
}
