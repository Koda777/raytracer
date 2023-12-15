/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Config
*/

#include "config/ConfigManager.hpp"
#include "config/ConfigUtils.hpp"
#include "constant.hpp"
#include <iostream>
#include <sstream>

ConfigManager::ConfigManager(const std::string configFile) : m_configFileName{configFile}
{
    parse();
}

void ConfigManager::parse()
{
    try {
        config.readFile(m_configFileName.c_str());

        parseApp();
        parseRenderer();
        parsePrimitives();
        parseLights();
        parseCamera();

    } catch (const libconfig::FileIOException &e) {
        std::cout << "Error reading configuration file: " << e.what() << std::endl;
        throw e;
    } catch (const libconfig::ParseException &e) {
        std::cout << "Error parsing .cfg " << e.what() << std::endl;
        throw e;
    } catch (const libconfig::SettingNotFoundException &e) {
        std::cout << "Error parsing settings: " << e.getPath() << " not found" << std::endl;
        throw e;
    } catch (const libconfig::SettingTypeException &e) {
        std::cout << "Error parsing settings: " << e.getPath() << " has invalid type" << std::endl;
        throw e;
    }

    std::cout << "[CONFIG] Lights finded:" << m_lightConfigList.size() << std::endl;
    std::cout << "[CONFIG] Primitives finded:" << m_primitiveConfigList.size() << std::endl;
    std::cout << "[CONFIG] File successfully parsed" << std::endl;
#if DEBUG
    displayConfig();
#endif
}

void ConfigManager::displayConfig()
{
    std::cout << "camera settings: \n" << m_configCamera << std::endl;
    std::cout << "app settings: \n" << m_configApp << std::endl;
    std::cout << "renderer settings: \n" << m_configRenderer << std::endl;
    for (auto &prim : m_primitiveConfigList) std::cout << prim << std::endl;
    for (auto &light : m_lightConfigList) std::cout << light << std::endl;
}

void ConfigManager::parsePrimitives()
{
    try {
        const libconfig::Setting &primitives = config.lookup("primitives");
        if (primitives.exists(IDENTIFIER_SPHERE)) {
            const libconfig::Setting &spheres = primitives.lookup(IDENTIFIER_SPHERE);
            for (auto &sphere : spheres) {
                m_primitiveConfigList.emplace_back(parseSphere(sphere));
            }
        }
        if (primitives.exists(IDENTIFIER_PLANE)) {
            const libconfig::Setting &planes = primitives.lookup(IDENTIFIER_PLANE);
            for (auto &plane : planes) {
                m_primitiveConfigList.emplace_back(parsePlane(plane));
            }
        }
        if (primitives.exists(IDENTIFIER_CYLINDER)) {
            const libconfig::Setting &cylinders = primitives.lookup(IDENTIFIER_CYLINDER);
            for (auto &cylinder : cylinders) {
                m_primitiveConfigList.emplace_back(parseCylinder(cylinder));
            }
        }

    } catch (const libconfig::SettingNotFoundException &e) {
    }
}

void ConfigManager::parseLights()
{
    try {
        const libconfig::Setting &primitives = config.lookup("lights");
        {
            const libconfig::Setting &ambients = primitives.lookup("ambient");
            for (auto &ambient : ambients) m_lightConfigList.emplace_back(parseLightAmbient(ambient));
        }
        {
            const libconfig::Setting &directionals = primitives.lookup("directional");
            for (auto &directional : directionals) m_lightConfigList.emplace_back(parseLightDirectional(directional));
        }

    } catch (const libconfig::SettingNotFoundException &) {
    }
}

void ConfigManager::parseCamera()
{
    const libconfig::Setting &camera = config.lookup("camera");

    m_configCamera.identifier = std::string(IDENTIFIER_CAMERA);
    m_configCamera.position = parseSfVector(camera.lookup("position"));
    m_configCamera.direction = parseSfVector(camera.lookup("direction"));
    m_configCamera.fov = camera.lookup("fieldOfView");
    m_configCamera.width = camera.lookup("resolution.width");
    m_configCamera.height = camera.lookup("resolution.height");

    if (m_configCamera.width <= 0 || m_configCamera.height <= 0)
        throw std::runtime_error("Invalid Window Size");
}

void ConfigManager::parseRenderer()
{
    const libconfig::Setting &renderer = config.lookup("renderer");

    m_configRenderer.backgroundColor = parseSfColor(renderer.lookup("backgroundColor"));
    m_configRenderer.multiplier = renderer.lookup("multiplier");
    m_configRenderer.bounces = renderer.lookup("bounces");
}

void ConfigManager::parseApp()
{
    const libconfig::Setting &app = config.lookup("app");

    m_configApp.gui = app.lookup("gui");
    app.lookupValue("outputFile", m_configApp.outputFile);
    m_configApp.maxFps = app.lookup("maxFps");
    m_configApp.sleepTime = app.lookup("sleepTime");
}
