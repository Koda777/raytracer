/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** FactoryPrimitive
*/

#include "FactoryPrimitive.hpp"
#include "LimitedCylinder.hpp"
#include "Plane.hpp"
#include "Sphere.hpp"

FactoryPrimitive::FactoryPrimitive()
{
    m_constructors = {
        {"sphere",
            []() {
                return std::make_unique<Sphere>();
            }},
        {"plane",
            []() {
                return std::make_unique<Plane>();
            }},
        {"limitedCylinder",
            []() {
                return std::make_unique<LimitedCylinder>();
            }},
    };
}

std::unique_ptr<IPrimitive> FactoryPrimitive::create(const std::string &name)
{
    if (m_constructors.count(name) == 0)
        throw std::runtime_error("Primitive not found " + name);
    return m_constructors[name]();
}
