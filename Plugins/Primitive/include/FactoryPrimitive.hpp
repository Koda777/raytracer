/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** FactoryPrimitive
*/

#pragma once
#include "IPrimitive.hpp"
#include "factory/IFactory.hpp"
#include <functional>
#include <map>

class FactoryPrimitive : public IFactory<IPrimitive>
{
    public:
        FactoryPrimitive();
        ~FactoryPrimitive() = default;

        using PrimitiveConstructors = std::map<std::string, std::function<std::unique_ptr<IPrimitive>()>>;

        std::unique_ptr<IPrimitive> create(const std::string &) final;

    private:
        PrimitiveConstructors m_constructors;
};
