/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** entrypoint
*/

#include "FactoryCamera.hpp"
#include <iostream>
#include <memory>

void __attribute__((constructor)) calledFirst();
void __attribute__((destructor)) calledLast();

void calledFirst()
{
    std::cout << "[Camera] Loading" << '\n';
}

void calledLast()
{
    std::cout << "[Camera] UnLoading" << '\n';
}

extern "C" {
std::unique_ptr<FactoryCamera> create()
{
    return std::make_unique<FactoryCamera>();
}
}
