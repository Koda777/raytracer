/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** entrypoint
*/

#include "FactoryLight.hpp"
#include <iostream>
#include <memory>

void __attribute__((constructor)) calledFirst();
void __attribute__((destructor)) calledLast();

void calledFirst()
{
    std::cout << "[Light] Loading" << '\n';
}

void calledLast()
{
    std::cout << "[Light] UnLoading" << '\n';
}

extern "C" {
std::unique_ptr<FactoryLight> create()
{
    return std::make_unique<FactoryLight>();
}
}
