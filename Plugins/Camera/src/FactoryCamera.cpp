/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** FactoryCamera
*/

#include "FactoryCamera.hpp"
#include "Camera.hpp"

FactoryCamera::FactoryCamera()
{
    m_constructors = {
        {"classical",
            []() {
                return std::make_unique<Camera>();
            }},
    };
}

std::unique_ptr<ICamera> FactoryCamera::create(const std::string &name)
{
    if (m_constructors.count(name) == 0)
        throw std::runtime_error("Camera not found " + name);
    return m_constructors[name]();
}
