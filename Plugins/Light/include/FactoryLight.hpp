/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** FactoryLight
*/

#pragma once
#include "ILight.hpp"
#include "factory/IFactory.hpp"
#include <functional>
#include <map>

class FactoryLight : public IFactory<ILight>
{
    public:
        FactoryLight();
        ~FactoryLight() = default;

        using LightConstructors = std::map<std::string, std::function<std::unique_ptr<ILight>()>>;

        std::unique_ptr<ILight> create(const std::string &) final;

    private:
        LightConstructors m_constructors;
};
