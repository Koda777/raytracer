/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Camera
*/

#pragma once
#include "ICamera.hpp"

class Camera : public ICamera
{
    private:
        sf::Vector3f m_direction;
        sf::Vector3f m_position;
        sf::Vector3f *m_cached_ray_direction;
        int m_width;
        int m_height;
        float m_fov;
        float m_aspect_ratio;

    public:
        Camera();
        ~Camera() = default;

        void calculateRayDirection(int, int);

        // Getter
        sf::Vector3f *getRayDirection(int, int);
        sf::Vector3f getCameraPosition() const;

        // Setter
        ICamera &setFOV(float) final;
        ICamera &setDirection(sf::Vector3f) final;
        ICamera &setPosition(sf::Vector3f) final;
};
