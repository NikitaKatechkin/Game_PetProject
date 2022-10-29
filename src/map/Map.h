#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include "../window/Window.h"

#include <vector>

class Map
{
public:
    Map(const std::string& configFilePath = "../../configs/map.config");
    ~Map();

public:
    void draw(Window* window);
    void drawFOV(Window* window, const sf::Vector2f& playerPixelPos);

private:
    void Initialize(const std::string& configFilePath);

private:
    sf::Vector2u m_size;
    //sf::RectangleShape* m_units = nullptr;
    std::vector<sf::RectangleShape> m_units;
};

#endif