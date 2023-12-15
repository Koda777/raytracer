/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SharedLibHandler
*/

#pragma once
#include "SharedLibLoader.hpp"
#include "pluginDesc.hpp"
#include <memory>

template <typename Interface_t>
class SharedLibHandler
{
    private:
        using create_interface_t = std::unique_ptr<Interface_t> (*)();

        std::unique_ptr<Interface_t> _interface;
        create_interface_t _constructor;
        SharedLibLoader sharedLibLoader;

    public:
        SharedLibHandler();
        SharedLibHandler(const PluginDesc &, const PluginDesc::PluginDescType);
        ~SharedLibHandler();

        void load(const PluginDesc &, const PluginDesc::PluginDescType);
        Interface_t &getInterface();
};
