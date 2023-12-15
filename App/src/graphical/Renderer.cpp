/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Renderer
*/

#include "graphical/Renderer.hpp"

#include <SFML/System.hpp>
#include <cstring>
#include <iostream>
#include <random>

int floatRand(const float &min, const float &max)
{
    static thread_local std::mt19937 generator;
    std::uniform_real_distribution<float> distribution(min, max);
    return distribution(generator);
}

Renderer::Renderer(int &width, int &height, ConfigRenderer &configRenderer)
    : _config{configRenderer}, _width{width}, _height{height}, _pixelsBuffer{new sf::Uint8[width * height * 4]}, _pixelsAccumulationBuffer{new sf::Uint64[width * height * 4]}, _frameIndex{1}
{
    memset(_pixelsAccumulationBuffer, 0, _width * _height * 4);

    // set up thread tiles
    for (int i = 0; i < THREAD_NUMBER; i++) {
        sf::IntRect tiles((i * (_width / THREAD_NUMBER)), // startX,
            0,                                            // startY,
            (i + 1) * (_width / THREAD_NUMBER),           // endX,
            _height                                       // endY
        );

        threads[i] = std::make_unique<sf::Thread>([this, tiles]() {
            this->renderRegion(tiles);
        });
    }
}

void Renderer::setPixelColor(sf::Vector2f coord, sf::Color pixelColor)
{
    int index = (coord.x + coord.y * _width) * 4; // 4 bytes per pixel (RGBA)

    _pixelsBuffer[index] = pixelColor.r;
    _pixelsBuffer[index + 1] = pixelColor.g;
    _pixelsBuffer[index + 2] = pixelColor.b;
    _pixelsBuffer[index + 3] = pixelColor.a;
}

void Renderer::resetAccumulationBuffer()
{
    memset(_pixelsAccumulationBuffer, 0, _width * _height * 4);
    _frameIndex = 1;
}

void Renderer::setpixelsAccumulationColor(sf::Vector2f coord, sf::Color pixelColor)
{
    int index = (coord.x + coord.y * _width) * 4; // 4 bytes per pixel (RGBA)

    _pixelsAccumulationBuffer[index] += pixelColor.r;
    _pixelsAccumulationBuffer[index + 1] += pixelColor.g;
    _pixelsAccumulationBuffer[index + 2] += pixelColor.b;
    _pixelsAccumulationBuffer[index + 3] += pixelColor.a;

    _pixelsBuffer[index] = _pixelsAccumulationBuffer[index] / _frameIndex;
    _pixelsBuffer[index + 1] = _pixelsAccumulationBuffer[index + 1] / _frameIndex;
    _pixelsBuffer[index + 2] = _pixelsAccumulationBuffer[index + 2] / _frameIndex;
    _pixelsBuffer[index + 3] = _pixelsAccumulationBuffer[index + 3] / _frameIndex;
}

sf::Uint8 *Renderer::render(ICamera *camera, Scene &scene)
{
    _activeCamera = camera;
    _activeScene = &scene;

#ifdef RELEASE
    sf::IntRect tiles(0, // startX,
        0,               // startY,
        _width,          // endX,
        _height          // endY
    );
    renderRegion(tiles);
#else
    for (auto &thread : threads) thread->launch();
    for (auto &thread : threads) thread->wait();
#endif

    _frameIndex++;
    return _pixelsBuffer;
}

void Renderer::renderRegion(sf::IntRect tiles)
{
    for (int y = tiles.top; y < tiles.height; y++) {
        for (int x = tiles.left; x < tiles.width; x++) {
            setpixelsAccumulationColor(sf::Vector2f{(float)x, (float)y}, rayGen(x, y));
        }
    }
}

sf::Color Renderer::rayGen(int x, int y)
{
    Ray ray;
    ray.origin = _activeCamera->getCameraPosition();
    ray.direction = _activeCamera->getRayDirection(_width, _height)[x + y * _width];

    sf::Color pixelColor = sf::Color(0.0);
    float multiplier = _config.multiplier;

    for (size_t i = 0; i < (size_t)_config.bounces; i++) {
        HitPayload payload = TraceRay(ray);

        if (payload.hitDistance < 0.0f) {
            rayShadingMiss(pixelColor, multiplier);
            break;
        } else {
            rayShadingSucess(pixelColor, payload, ray, multiplier);
        }
    }
    return pixelColor;
}

void Renderer::rayShadingMiss(sf::Color &pixelColor, float &multiplier)
{
    pixelColor += _config.backgroundColor * multiplier;
}

void Renderer::rayShadingSucess(sf::Color &pixelColor, HitPayload &payload, Ray &ray, float &multiplier)
{
    auto &currentPrimitive = _activeScene->getPrimitive(payload.objectIndex).get();
    auto &currentLights = _activeScene->getLight();

    for (auto &currentLight : currentLights) {
        pixelColor += currentPrimitive.HitObject(ray, payload, *currentLight) * multiplier;
        multiplier *= 0.5f;

        auto &material = currentPrimitive.getMaterial();
        ray.origin = payload.worldPosition + payload.worldNormal * 0.0001f;
        float random = floatRand(0.5, 0.5);
        ray.direction = Vector3D::reflect(ray.direction, (payload.worldNormal + (material.roughness * sf::Vector3f(random, random, random))));
    }
}

HitPayload Renderer::TraceRay(const Ray &ray)
{
    int indexClosestPrimitive = -1;
    float hitDistance = std::numeric_limits<float>::max();

    for (int index = 0; index < _activeScene->getPrimitiveSize(); index++) {
        auto primitive = _activeScene->getPrimitive(index);

        float hitDistanceCurrent = primitive.get().intersection(ray);

        if (hitDistanceCurrent > 0 && hitDistanceCurrent < hitDistance) {
            hitDistance = hitDistanceCurrent;
            indexClosestPrimitive = index;
        }
    }
    if (indexClosestPrimitive < 0)
        return Miss(ray);

    return ClosestHit(ray, hitDistance, indexClosestPrimitive);
}

HitPayload Renderer::ClosestHit(const Ray &ray, float hitDistance, int objectIndex)
{
    HitPayload payload;
    payload.hitDistance = hitDistance;
    payload.objectIndex = objectIndex;

    const IPrimitive &closestPrimitive = _activeScene->getPrimitive(payload.objectIndex);

    sf::Vector3f origin = ray.origin - closestPrimitive.getPosition();
    payload.worldPosition = origin + ray.direction * hitDistance;
    payload.worldNormal = Vector3D::normalize(payload.worldPosition);
    payload.worldPosition += closestPrimitive.getPosition();

    return payload;
}

HitPayload Renderer::Miss(const Ray &)
{
    HitPayload payload;
    payload.hitDistance = -1.0f;
    return payload;
}
