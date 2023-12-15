/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** light
*/

#pragma once
#include "ILight.hpp"

class Light : public ILight
{
    private:
        sf::Vector3f m_position;
        float m_intensity;

    public:
        Light();
        Light(sf::Vector3f, float);
        ~Light() = default;

        // Getter
        sf::Vector3f getPosition() const final;

        float getIntensity() const final;

        // Setter
        ILight &setPosition(const sf::Vector3f) final;

        ILight &setIntensity(float) final;
};
