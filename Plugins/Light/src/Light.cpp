/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Light
*/

#include "Light.hpp"

Light::Light() : m_position{sf::Vector3f(0.f, 0.f, 0.f)}, m_intensity{0.f} {}
Light::Light(sf::Vector3f position, float intensity) : m_position{position}, m_intensity{intensity} {}

sf::Vector3f Light::getPosition() const
{
    return m_position;
};

float Light::getIntensity() const
{
    return m_intensity;
};

ILight &Light::setPosition(const sf::Vector3f position)
{
    m_position = position;
    return *this;
}

ILight &Light::setIntensity(float intensity)
{
    m_intensity = intensity;
    return *this;
}
