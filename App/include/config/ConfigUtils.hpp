/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ConfigUtils
*/

#pragma once
#include "ConfigDefault.hpp"
#include "myUtils.hpp"
#include <libconfig.h++>

sf::Vector3f parseSfVector(const libconfig::Setting &);

sf::Color parseSfColor(const libconfig::Setting &);

ConfigPrimitive parseSphere(const libconfig::Setting &);

ConfigPrimitive parsePlane(const libconfig::Setting &);

ConfigPrimitive parseCylinder(const libconfig::Setting &);

ConfigPrimitive::ConfigMaterial parseMaterial(const libconfig::Setting &);

ConfigLight parseLightDirectional(const libconfig::Setting &setting);

ConfigLight parseLightAmbient(const libconfig::Setting &setting);
