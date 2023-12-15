/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** App
*/

#include "App.hpp"
#include "constant.hpp"
#include "myUtils.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

App::App(ConfigManager &configManager)
    : _configManager{configManager}
    , _width{configManager.m_configCamera.width}
    , _height{configManager.m_configCamera.height}
    , _window{sf::VideoMode(_width, _height), APP_NAME}
    , _pluginsLoader{PluginsLoader(PLUGINS_DIRECTORY_PATH)}
    , _scene{Scene(configManager.m_primitiveConfigList, configManager.m_lightConfigList)}
    , _camera{nullptr}
    , _renderer{Renderer(_width, _height, configManager.m_configRenderer)}
    , _gui{_currentRenderTime}
    , _deltaClock{sf::Clock()}
    , _renderTexture{}
    , _sprite{}
{
    // init gui rendering
    if (_configManager.m_configApp.gui) {
        _renderTexture.create(_width, _height);
        _sprite.setTexture(_renderTexture);
        _window.setFramerateLimit(_configManager.m_configApp.maxFps);
    }

    // init scene
    _pluginsLoader.load();
    _scene.load(_pluginsLoader.m_primitiveFactory.getInterface(), _pluginsLoader.m_lightFactory.getInterface());

    // init camera
    _camera = _pluginsLoader.m_cameraFactory.getInterface().create("classical");
    auto &cameraConfig = _configManager.m_configCamera;
    _camera->setDirection(cameraConfig.direction).setPosition(cameraConfig.position).setFOV(cameraConfig.fov);
}

void App::handleEvent()
{
    while (_window.pollEvent(_event)) {
        switch (_event.type) {
            case sf::Event::Closed: _window.close(); break;

            case sf::Event::KeyPressed:
                if (_event.key.code == sf::Keyboard::Escape) {
                    _window.close();
                    _gui.m_window.close();
                }
                if (_event.key.code == sf::Keyboard::Space)
                    saveToPPMfile();
                if (_event.key.code == sf::Keyboard::C)
                    _renderer.resetAccumulationBuffer();
                break;

            default: break;
        }
    }
    return _gui.handleEvent([this]() {
        this->_window.close();
    });
}

void App::runGUI()
{
    sf::Uint8 *pixelsBuffer;

    while (_window.isOpen()) {
        handleEvent();
        _window.clear();

        setTimer();
        pixelsBuffer = _renderer.render(_camera.get(), _scene);
        setTimer();

        _renderTexture.update(pixelsBuffer);
        _window.draw(_sprite);
        _window.display();
        _gui.render();
        sf::sleep(sf::milliseconds(_configManager.m_configApp.sleepTime));
    }
}

void App::runFile()
{
    std::string filename = (_configManager.m_configApp.outputFile.empty()) ? generateUniqueFilename(".ppm", SCREENSHT_DIRECTORY_PATH) : _configManager.m_configApp.outputFile;

    std::ofstream outputFile(filename, std::ios::binary);
    outputFile << "P6\n" << _width << " " << _height << "\n255\n";
    sf::Uint8 *pixelbuffer = _renderer.render(_camera.get(), _scene);

    for (unsigned int i = 0; i < (unsigned int)_width * _height * 4; i += 4) {
        outputFile << pixelbuffer[i] << pixelbuffer[i + 1] << pixelbuffer[i + 2];
    }
    std::cout << "fie saved to: " << filename << "\n";
    outputFile.close();
}

void App::run()
{
    if (_configManager.m_configApp.gui) {
        runGUI();
    } else {
        runFile();
    }
}

void App::saveToPPMfile()
{
    const sf::Vector2u windowSize = _window.getSize();
    std::string filename = generateUniqueFilename(".ppm", SCREENSHT_DIRECTORY_PATH);

    sf::Texture texture;
    texture.create(windowSize.x, windowSize.y);
    texture.update(_window);

    sf::Image screenshot = texture.copyToImage();
    std::ofstream outputFile(filename, std::ios::binary);
    outputFile << "P6\n" << windowSize.x << " " << windowSize.y << "\n255\n";

    const sf::Uint8 *pixels = screenshot.getPixelsPtr();
    for (unsigned int i = 0; i < windowSize.x * windowSize.y * 4; i += 4) {
        outputFile << pixels[i] << pixels[i + 1] << pixels[i + 2];
    }
    std::cout << "screenshot saved to " << filename << "\n";
    outputFile.close();
}

void App::setTimer()
{
    _currentRenderTime = _deltaClock.restart();
}

int appEntryPoint(const std::string &configFilePath)
{
    ConfigManager configManager(configFilePath);
    App raytracer(configManager);

    raytracer.run();

    return 0;
}
