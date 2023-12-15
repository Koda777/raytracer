/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Camera
*/

#include "Camera.hpp"
#include "myUtils.hpp"
#include <cmath>
#include <iostream>

Camera::Camera() : m_direction{sf::Vector3f{0, 0, -1}}, m_position{sf::Vector3f{0, 0, 3}}, m_cached_ray_direction{nullptr}, m_width{0}, m_height{0}, m_fov{110}, m_aspect_ratio{0} {}

void Camera::calculateRayDirection(int width, int height)
{
    float tan_half_fov = std::tan(radians(m_fov / 2.0f));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            sf::Vector2f coord((float)x / width, (float)y / height);
            float dir_x = ((2.0f * coord.x) - 1.0f) * m_aspect_ratio * tan_half_fov;
            float dir_y = (1.0f - (2.0f * coord.y)) * tan_half_fov;
            sf::Vector3f rayDirection(dir_x, dir_y, -1.0f);

            m_cached_ray_direction[x + y * width] = rayDirection;
        }
    }
}

sf::Vector3f *Camera::getRayDirection(int width, int height)
{
    static bool direction_changed = true;
    m_width = width;
    m_height = height;

    if (direction_changed) {
        delete[] m_cached_ray_direction;

        m_aspect_ratio = (float)width / height;
        m_cached_ray_direction = new sf::Vector3f[width * height];
        calculateRayDirection(m_width, m_height);
        direction_changed = false;
    }
    return m_cached_ray_direction;
}

sf::Vector3f Camera::getCameraPosition() const
{
    return m_position;
}

ICamera &Camera::setFOV(float fov)
{
    m_fov = fov;
    return *this;
}

ICamera &Camera::setDirection(sf::Vector3f direction)
{
    m_direction = direction;
    return *this;
}

ICamera &Camera::setPosition(sf::Vector3f position)
{
    m_position = position;
    return *this;
}
