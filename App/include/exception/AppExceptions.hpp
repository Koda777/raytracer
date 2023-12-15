/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** AppExceptions
*/

#pragma once
#include "BasicExceptions.hpp"

namespace CoreExceptions
{
    class RuntimeExceptions : public BasicExceptionWithMessage
    {
        public:
            RuntimeExceptions(const std::string &);
    };
} // namespace CoreExceptions
