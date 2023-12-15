/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Sphere
*/

#include "Sphere.hpp"

Sphere::Sphere() : m_radius{0.0f}, m_position{sf::Vector3f(0.0f, 0.0f, 0.0f)}, m_material{Material()} {}

Sphere::Sphere(float radius, sf::Vector3f position, Material &material) : m_radius{radius}, m_position{position}, m_material{material} {};

float Sphere::intersection(const Ray &ray) const
{
    sf::Vector3f sphereOrigin = ray.origin - m_position;

    float a = Vector3D::dot(ray.direction, ray.direction);
    float b = 2.0f * Vector3D::dot(ray.direction, sphereOrigin);
    float c = Vector3D::dot(sphereOrigin, sphereOrigin) - m_radius * m_radius;

    float discriminant = b * b - 4.0f * a * c;

    if (discriminant <= 0.0f)
        return -1;

    // Find intersection point closest
    float closestT = (-b - std::sqrt(discriminant)) / (2.0f * a);
    float t0 = (-b + std::sqrt(discriminant)) / (2.0f * a);
    if (t0 < 0)
        return -1;
    return closestT;
}

sf::Color Sphere::HitObject(const Ray &ray, const HitPayload &payload, const ILight &light) const
{
    sf::Vector3f lightPoint = light.getPosition();

    sf::Vector3f sphereOrigin = ray.origin - m_position;
    sf::Vector3f intersectionPoint = sphereOrigin + (ray.direction * payload.hitDistance);
    sf::Vector3f normal = Vector3D::normalize(intersectionPoint);

    // diffuse reflection color
    sf::Vector3f lightDirection = Vector3D::normalize(lightPoint);
    float lightIntensity = std::max(0.0f, Vector3D::dot(normal, -lightDirection));
    return sf::Color(std::floor(lightIntensity * m_material.albedo.r), std::floor(lightIntensity * m_material.albedo.g), std::floor(lightIntensity * m_material.albedo.b));
}

sf::Vector3f Sphere::getPosition() const
{
    return m_position;
}

const Material &Sphere::getMaterial() const
{
    return m_material;
}

IPrimitive &Sphere::setMaterial(Material material)
{
    m_material = material;
    return *this;
}

IPrimitive &Sphere::setPosition(sf::Vector3f position)
{
    m_position = position;
    return *this;
}

IPrimitive &Sphere::setNormal(sf::Vector3f)
{
    return *this;
}

IPrimitive &Sphere::setHeight(float)
{
    return *this;
}

IPrimitive &Sphere::setRadius(float radius)
{
    m_radius = radius;
    return *this;
}
