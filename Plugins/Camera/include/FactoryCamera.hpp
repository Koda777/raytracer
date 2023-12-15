/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** FactoryCamera
*/

#pragma once
#include "ICamera.hpp"
#include "factory/IFactory.hpp"
#include <functional>
#include <map>

class FactoryCamera : public IFactory<ICamera>
{
    public:
        FactoryCamera();
        ~FactoryCamera() = default;

        using CameraConstructors = std::map<std::string, std::function<std::unique_ptr<ICamera>()>>;

        std::unique_ptr<ICamera> create(const std::string &) final;

    private:
        CameraConstructors m_constructors;
};
