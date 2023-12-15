/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** dlfcnExceptions
*/

#pragma once
#include "BasicExceptions.hpp"

namespace DlfcnExceptions
{
    class CannotOpenExceptions : public BasicExceptionWithMessage
    {
        public:
            CannotOpenExceptions(const std::string &);
    };

    class CannotLoadExceptions : public BasicExceptionWithMessage
    {
        public:
            CannotLoadExceptions(const std::string &);
    };
} // namespace DlfcnExceptions