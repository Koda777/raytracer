/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** GUI
*/

#include <functional>

#include "constant.hpp"
#include "graphical/GUI.hpp"

GUI::GUI(sf::Time &currentRenderTime) : m_window{sf::VideoMode(GUI::width, GUI::height), "GUI RayTracer"}, m_currentRenderTime{currentRenderTime}
{
    if (!_font.loadFromFile(PATH_FONT))
        throw std::runtime_error("Failed to load font");
    m_textFPS = sf::Text("renderingTime:", _font);
    m_textFPS.setFillColor(sf::Color::White);
    m_textFPS.setCharacterSize(20);
    m_textFPS.setPosition(10, 10);
}

GUI::~GUI() {}

void GUI::render()
{
    if (!m_window.isOpen())
        return;
    m_window.clear();

    std::string str = "renderingTime: " + std::to_string(m_currentRenderTime.asMilliseconds()) + " ms";
    m_textFPS.setString(str);

    // draw
    m_window.draw(m_textFPS);
    m_window.display();
}

void GUI::handleEvent(std::function<void()> closeCallBack)
{
    if (!m_window.isOpen())
        return;
    while (m_window.pollEvent(m_event)) {
        switch (m_event.type) {
            case sf::Event::Closed:
                closeCallBack();
                m_window.close();
                break;

            case sf::Event::KeyPressed:
                if (m_event.key.code == sf::Keyboard::Escape) {
                    closeCallBack();
                    m_window.close();
                }
            default: break;
        }
    }
}
