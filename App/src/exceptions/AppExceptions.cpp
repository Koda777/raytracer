/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** AppExceptions
*/

#include "exception/AppExceptions.hpp"

CoreExceptions::RuntimeExceptions::RuntimeExceptions(const std::string &errorMsgDetails) : BasicExceptionWithMessage("[Core]", "Cannot Open: " + errorMsgDetails) {}
