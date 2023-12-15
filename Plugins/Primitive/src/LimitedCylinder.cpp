/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Cylinder
*/

#include "LimitedCylinder.hpp"

LimitedCylinder::LimitedCylinder() {}
LimitedCylinder::LimitedCylinder(float radius, sf::Vector3f position, float height, Material &material) : m_radius(radius), m_position(position), m_height(height), m_material(material) {}

float LimitedCylinder::intersection(const Ray &ray) const
{
    sf::Vector3f localOrigin = ray.origin - m_position;
    sf::Vector3f localDirection = ray.direction;
    localDirection.y = 0;

    float a = localDirection.x * localDirection.x + localDirection.z * localDirection.z;
    float b = 2 * (localDirection.x * localOrigin.x + localDirection.z * localOrigin.z);
    float c = localOrigin.x * localOrigin.x + localOrigin.z * localOrigin.z - m_radius * m_radius;

    float discriminant = b * b - 4 * a * c;

    if (discriminant < 0)
        return -1;

    float t1 = (-b - std::sqrt(discriminant)) / (2 * a);
    // float t2 = (-b + std::sqrt(discriminant)) / (2 * a);

    if (t1 > 0 && localOrigin.y + t1 * localDirection.y >= 0 && localOrigin.y + t1 * localDirection.y <= m_height) {
        return t1;
    }
    return -1;
}

sf::Color LimitedCylinder::HitObject(const Ray &, const HitPayload &payload, const ILight &light) const
{
    sf::Vector3f localHitPoint = payload.worldPosition - m_position;
    float phi = atan2(localHitPoint.y, localHitPoint.x);
    if (phi < 0)
        phi += 2 * M_PI;
    // float u = phi / (2 * M_PI);
    // float v = localHitPoint.z / m_height;

    sf::Color textureColor = m_material.albedo;

    // sf::Vector3f view = -ray.direction;
    sf::Color lightingColor = m_material.albedo * light.getIntensity();
    sf::Color color = textureColor * lightingColor;
    return color;
}

sf::Vector3f LimitedCylinder::getPosition() const
{
    return m_position;
}

const Material &LimitedCylinder::getMaterial() const
{
    return m_material;
}

IPrimitive &LimitedCylinder::setMaterial(Material material)
{
    m_material = material;
    return *this;
}

IPrimitive &LimitedCylinder::setPosition(sf::Vector3f position)
{
    m_position = position;
    return *this;
}

IPrimitive &LimitedCylinder::setNormal(sf::Vector3f)
{
    return *this;
}

IPrimitive &LimitedCylinder::setHeight(float height)
{
    m_height = height;
    return *this;
}

IPrimitive &LimitedCylinder::setRadius(float radius)
{
    m_radius = radius;
    return *this;
}
