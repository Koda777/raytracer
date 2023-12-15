/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SharedLibLoader
*/

#include "SharedLibLoader.hpp"
#include <dlfcn.h>
#include <memory>
#include <stdexcept>
#include <string>

SharedLibLoader::SharedLibLoader() : _handle(nullptr, dlclose) {}

SharedLibLoader::SharedLibLoader(const std::string &libName, int flags) : _handle(nullptr, dlclose)
{
    this->open(libName, flags);
}

SharedLibLoader::~SharedLibLoader()
{
    _handle.release();
}

void SharedLibLoader::open(const std::string &libName, int flags)
{
    (void)flags;
    if (_handle != nullptr)
        _handle.release();

    void *handle = dlopen(libName.c_str(), RTLD_NOW);

    if (!handle)
        throw std::runtime_error(dlerror());
    _handle.reset(handle);
}

void SharedLibLoader::close() {}

std::string SharedLibLoader::error() const
{
    char *dl_error = dlerror();

    return (dl_error != nullptr) ? std::string{dl_error} : "";
}

void *SharedLibLoader::sym(const std::string &symbol)
{
    void *out;

    dlerror();
    out = dlsym(_handle.get(), symbol.c_str());

    std::string dlsym_error = error();
    if (!out || !dlsym_error.empty())
        throw std::runtime_error(dlsym_error);
    return out;
}

bool SharedLibLoader::isLibLoaded() const
{
    return _handle.operator bool();
}
