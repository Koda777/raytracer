/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SharedLibLoader
*/

#pragma once
#include <dlfcn.h>
#include <memory>
#include <vector>

class SharedLibLoader
{
    private:
        using CloseFunc = int (*)(void *);
        std::unique_ptr<void, CloseFunc> _handle;

    public:
        SharedLibLoader();
        SharedLibLoader(const std::string &, int = RTLD_NOW);
        ~SharedLibLoader();

        void open(const std::string &, int = RTLD_NOW);
        void close();
        std::string error() const;
        void *sym(const std::string &);
        bool isLibLoaded() const;
};
