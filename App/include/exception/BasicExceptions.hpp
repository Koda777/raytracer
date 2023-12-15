/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** BasicExceptions
*/

#pragma once
#include <string>

class BasicExceptionWithMessage : public std::exception
{
    public:
        BasicExceptionWithMessage(const std::string &errorAuthor, const std::string &errorMsg) : _errorMsg("--!" + errorAuthor + " " + errorMsg) {}

        [[nodiscard]] const char *what() const noexcept override { return _errorMsg.c_str(); }

    private:
        std::string _errorMsg;
};
