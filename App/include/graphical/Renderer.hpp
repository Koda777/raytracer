/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Renderer
*/

#pragma once
#include "HitPayload.hpp"
#include "ICamera.hpp"
#include "Material.hpp"
#include "Ray.hpp"
#include "config/ConfigDefault.hpp"
#include "constant.hpp"
#include "graphical/Scene.hpp"
#include "myUtils.hpp"
#include <array>
#include <memory>

class Renderer
{
    private:
        ConfigRenderer &_config;
        int &_width;
        int &_height;
        sf::Uint8 *_pixelsBuffer;
        sf::Uint64 *_pixelsAccumulationBuffer;
        ICamera *_activeCamera;
        Scene *_activeScene;
        int _frameIndex;
        std::array<std::unique_ptr<sf::Thread>, THREAD_NUMBER> threads;

    public:
        Renderer(int &, int &, ConfigRenderer &);
        ~Renderer() = default;

        void setPixelColor(sf::Vector2f, sf::Color);
        void resetAccumulationBuffer();
        void setpixelsAccumulationColor(sf::Vector2f, sf::Color);
        sf::Uint8 *render(ICamera *, Scene &);
        void renderRegion(sf::IntRect);

        sf::Color rayGen(int, int);

        void rayShadingMiss(sf::Color &, float &);
        void rayShadingSucess(sf::Color &, HitPayload &, Ray &, float &);

        HitPayload TraceRay(const Ray &);
        HitPayload ClosestHit(const Ray &, float, int);
        HitPayload Miss(const Ray &);
};
