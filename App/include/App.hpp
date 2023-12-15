/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** App
*/

#pragma once
#include "ICamera.hpp"
#include "config/ConfigManager.hpp"
#include "graphical/GUI.hpp"
#include "graphical/Renderer.hpp"
#include "graphical/Scene.hpp"
#include "plugins/PluginsLoader.hpp"

class App
{
    private:
        ConfigManager &_configManager;
        int _width;
        int _height;
        sf::RenderWindow _window;
        PluginsLoader _pluginsLoader;
        Scene _scene;
        std::unique_ptr<ICamera> _camera;
        Renderer _renderer;
        GUI _gui;
        sf::Event _event;
        sf::Clock _deltaClock;
        sf::Time _currentRenderTime;
        sf::Texture _renderTexture;
        sf::Sprite _sprite;

    public:
        App(ConfigManager &);
        ~App() = default;

        void handleEvent();
        void runGUI();
        void runFile();
        void run();
        void saveToPPMfile();
        void setTimer();
};

// entrypoint

int appEntryPoint(const std::string &);
