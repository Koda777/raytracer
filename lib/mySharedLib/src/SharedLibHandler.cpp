/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SharedLibHandler
*/

#include "SharedLibHandler.hpp"
#include "ICamera.hpp"
#include "ILight.hpp"
#include "IPrimitive.hpp"
#include "factory/IFactory.hpp"

template <typename Interface_t>
SharedLibHandler<Interface_t>::SharedLibHandler() : _interface{nullptr}
{}

template <typename Interface_t>
SharedLibHandler<Interface_t>::SharedLibHandler(const PluginDesc &lib, const PluginDesc::PluginDescType expected_type) : _interface{nullptr}
{
    load(lib, expected_type);
}

template <typename Interface_t>
SharedLibHandler<Interface_t>::~SharedLibHandler()
{}

template <typename Interface_t>
void SharedLibHandler<Interface_t>::load(const PluginDesc &lib, const PluginDesc::PluginDescType expected_type)
{
    if (lib.type != expected_type)
        throw std::runtime_error((lib.name.empty()) ? "lib not found" : "wrong lib type: " + lib.name);

    sharedLibLoader.open(lib.path);
    _constructor = reinterpret_cast<create_interface_t>(sharedLibLoader.sym("create"));
    _interface = _constructor ? _constructor() : nullptr;

    if (!_interface)
        throw std::runtime_error("failed loading lib");
}

template <typename Interface_t>
Interface_t &SharedLibHandler<Interface_t>::getInterface()
{
    return *_interface;
}

template class SharedLibHandler<IFactory<ICamera>>;
template class SharedLibHandler<IFactory<ILight>>;
template class SharedLibHandler<IFactory<IPrimitive>>;
