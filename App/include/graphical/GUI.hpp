/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** GUI
*/

#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

class GUI
{
    private:
        sf::RenderWindow m_window;
        sf::Event m_event;
        sf::Time &m_currentRenderTime;
        sf::Font _font;
        sf::Text m_textFPS;

        static const int width = 500;
        static const int height = 400;

    public:
        GUI(sf::Time &);
        ~GUI();

        void render();
        void handleEvent(std::function<void()>);

        friend class App;
};
