/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PluginsLoader
*/

#pragma once
#include "ICamera.hpp"
#include "ILight.hpp"
#include "IPrimitive.hpp"
#include "PluginsFileManager.hpp"
#include "SharedLibHandler.hpp"
#include "factory/IFactory.hpp"

using IPrimitiveFactory = IFactory<IPrimitive>;
using ILightFactory = IFactory<ILight>;
using ICameraFactory = IFactory<ICamera>;

class PluginsLoader
{
    private:
        PluginsFileManager m_fileManager;

        SharedLibHandler<IPrimitiveFactory> m_primitiveFactory;
        SharedLibHandler<ICameraFactory> m_cameraFactory;
        SharedLibHandler<ILightFactory> m_lightFactory;

        void loadPrimitive();
        void loadLights();
        void loadCamera();

    public:
        PluginsLoader(const std::string);
        ~PluginsLoader();

        void load();

        friend class App;
};
