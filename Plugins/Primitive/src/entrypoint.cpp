/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** entrypoint
*/

#include "FactoryPrimitive.hpp"
#include <iostream>
#include <memory>

void __attribute__((constructor)) calledFirst();
void __attribute__((destructor)) calledLast();

void calledFirst()
{
    std::cout << "[Primitive] Loading" << '\n';
}

void calledLast()
{
    std::cout << "[Primitive] UnLoading" << '\n';
}

extern "C" {
std::unique_ptr<FactoryPrimitive> create()
{
    return std::make_unique<FactoryPrimitive>();
}
}
