/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** confiugUtils
*/

#include "config/ConfigUtils.hpp"
#include "config/ConfigDefault.hpp"
#include "constant.hpp"
#include <iostream>

sf::Vector3f parseSfVector(const libconfig::Setting &setting)
{
    float x = 0.f, y = 0.f, z = 0.f;

    if (setting.exists("x"))
        x = setting.lookup("x");
    if (setting.exists("y"))
        y = setting.lookup("y");
    if (setting.exists("z"))
        z = setting.lookup("z");
    return sf::Vector3f(x, y, z);
}

sf::Color parseSfColor(const libconfig::Setting &setting)
{
    int r = setting["r"];
    int g = setting["g"];
    int b = setting["b"];
    int a = 255;
    if (setting.exists("a"))
        a = setting.lookup("a");
    return sf::Color(r, g, b, a);
}

ConfigPrimitive::ConfigMaterial parseMaterial(const libconfig::Setting &setting)
{
    sf::Color albedo = parseSfColor(setting.lookup("albedo"));
    float roughness = setting.lookup("roughness");

    return ConfigPrimitive::ConfigMaterial{albedo, roughness};
}

ConfigPrimitive parseSphere(const libconfig::Setting &setting)
{
    ConfigPrimitive configPrimitive;

    configPrimitive.identifier = std::string(IDENTIFIER_SPHERE);
    configPrimitive.material = parseMaterial(setting.lookup("material"));
    configPrimitive.radius = setting.lookup("radius");
    configPrimitive.position = parseSfVector(setting.lookup("position"));
    configPrimitive.normal = sf::Vector3f(0, 0, 0);
    return configPrimitive;
}

ConfigPrimitive parsePlane(const libconfig::Setting &setting)
{
    ConfigPrimitive configPrimitive;

    configPrimitive.identifier = std::string(IDENTIFIER_PLANE);
    configPrimitive.material = parseMaterial(setting.lookup("material"));
    configPrimitive.position = parseSfVector(setting.lookup("position"));
    configPrimitive.normal = parseSfVector(setting.lookup("normal"));
    return configPrimitive;
}

ConfigPrimitive parseCylinder(const libconfig::Setting &setting)
{
    ConfigPrimitive configPrimitive;

    configPrimitive.identifier = std::string(IDENTIFIER_CYLINDER);
    configPrimitive.material = parseMaterial(setting.lookup("material"));
    configPrimitive.radius = setting.lookup("radius");
    configPrimitive.height = setting.lookup("height");
    configPrimitive.position = parseSfVector(setting.lookup("position"));
    configPrimitive.normal = sf::Vector3f(0, 0, 0);
    return configPrimitive;
}

ConfigLight parseLightDirectional(const libconfig::Setting &setting)
{
    ConfigLight configPrimitive;
    configPrimitive.identifier = std::string(IDENTIFIER_DIRECTIONAL);
    configPrimitive.position = parseSfVector(setting.lookup("position"));
    configPrimitive.intensity = setting.lookup("intensity");
    return configPrimitive;
}

ConfigLight parseLightAmbient(const libconfig::Setting &setting)
{
    ConfigLight configPrimitive;

    configPrimitive.identifier = std::string(IDENTIFIER_AMBIENT);
    configPrimitive.position = parseSfVector(setting.lookup("position"));
    configPrimitive.intensity = setting.lookup("intensity");
    return configPrimitive;
}

// Struct default operator
std::ostream &operator<<(std::ostream &os, const ConfigPrimitive &configPrimitive)
{
    os << "ConfigPrimitive{" << std::endl;
    os << "  identifier: " << configPrimitive.identifier << std::endl;
    os << "  position: (" << configPrimitive.position << ")" << std::endl;
    os << "  normal: (" << configPrimitive.normal << std::endl;
    os << "  radius: " << configPrimitive.radius << std::endl;
    os << "  height: " << configPrimitive.height << std::endl;
    os << "  material: {" << std::endl;
    os << "    albedo: (" << configPrimitive.material.albedo;
    os << ")" << std::endl;
    os << "    roughness: " << configPrimitive.material.roughness << std::endl;
    os << "  }" << std::endl;
    os << "}";
    return os;
}

std::ostream &operator<<(std::ostream &os, const ConfigLight &configLight)
{
    os << "ConfigLight{" << std::endl;
    os << "  identifier: " << configLight.identifier << std::endl;
    os << "  position: (" << configLight.position << ")" << std::endl;
    os << "  intensity: " << configLight.intensity << std::endl;
    os << "}";
    return os;
}

std::ostream &operator<<(std::ostream &os, const ConfigCamera &configCamera)
{
    os << "ConfigCamera{" << std::endl;
    os << "  identifier: " << configCamera.identifier << std::endl;
    os << "  fov: " << configCamera.fov << std::endl;
    os << "  width: " << configCamera.width << std::endl;
    os << "  height: " << configCamera.height << std::endl;
    os << "  position: (" << configCamera.position << ")" << std::endl;
    os << "  direction: (" << configCamera.direction << ")" << std::endl;
    os << "}";
    return os;
}

std::ostream &operator<<(std::ostream &os, const ConfigRenderer &config)
{
    os << "ConfigRenderer: {" << std::endl;
    os << "  backgroundColor: (" << config.backgroundColor << ")" << std::endl;
    os << "  bounces: " << config.bounces << std::endl;
    os << "  multiplier: " << config.multiplier << std::endl;
    os << "}";
    return os;
}

std::ostream &operator<<(std::ostream &os, const ConfigApp &config)
{
    os << "ConfigApp: {" << std::endl;
    os << "  gui: " << std::boolalpha << config.gui << std::endl;
    os << "  outputFile: " << config.outputFile << std::endl;
    os << "  maxFps: " << config.maxFps << std::endl;
    os << "  sleepTime: " << config.sleepTime << std::endl;
    os << "}";
    return os;
}
