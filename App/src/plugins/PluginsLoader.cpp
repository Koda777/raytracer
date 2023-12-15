/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PluginsLoader
*/

#include "plugins/PluginsLoader.hpp"
#include <iostream>

PluginsLoader::PluginsLoader(const std::string path) : m_fileManager{PluginsFileManager(path)} {}

PluginsLoader::~PluginsLoader() {}

void PluginsLoader::loadPrimitive()
{
    PluginDesc primitivePluginDesc = m_fileManager.getLibByName("raytracer_primitive.so");
    m_primitiveFactory.load(primitivePluginDesc, PluginDesc::PRIMITIVE);
}
void PluginsLoader::loadLights()
{
    PluginDesc lightPluginDesc = m_fileManager.getLibByName("raytracer_light.so");
    m_lightFactory.load(lightPluginDesc, PluginDesc::LIGHT);
}
void PluginsLoader::loadCamera()
{
    PluginDesc cameraPluginDesc = m_fileManager.getLibByName("raytracer_camera.so");
    m_cameraFactory.load(cameraPluginDesc, PluginDesc::CAMERA);
}

void PluginsLoader::load()
{
#if DEBUG
    m_fileManager.displayAvailableLib();
#endif

    loadPrimitive();
    loadLights();
    loadCamera();
    try {
        // optional plugins
    } catch (const std::exception &e) {
        std::cout << "optionnal" << e.what() << std::endl;
    }
}