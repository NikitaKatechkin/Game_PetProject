#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include "../window/Window.h"

class Map
{
public:
    Map(const sf::Vector2u& size = sf::Vector2u(8, 8));
    ~Map();

public:
    void draw(Window* window);
    void drawFOV(Window* window, const sf::Vector2f& playerPixelPos);
private:
    sf::Vector2u m_size;
};

#endif