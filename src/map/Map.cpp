#include "Map.h"

#include <iostream>

static const float UNIT_HEIGHT = 32;
static const float UNIT_WIDTH = 32;

enum ColorNum
{
    Black = 0,
    Yellow,
    Green,
    Cyan,
    Magenta,
    Red,
    Blue,
    White,
};

static sf::Color numToColorConverter(const unsigned int number)
{
    sf::Color result;

    switch(ColorNum(number))
    {
    case ColorNum::Black:
    {
        result = sf::Color::Black;
        break;
    }
    case ColorNum::Yellow:
    {
        result = sf::Color::Yellow;
        break;
    }
    case ColorNum::Green:
    {
        result = sf::Color::Green;
        break;
    }
    case ColorNum::Cyan:
    {
        result = sf::Color::Cyan;
        break;
    }
    case ColorNum::Magenta:
    {
        result = sf::Color::Magenta;
        break;
    }
    case ColorNum::Red:
    {
        result = sf::Color::Red;
        break;
    }
    case ColorNum::Blue:
    {
        result = sf::Color::Blue;
        break;
    }
    case ColorNum::White:
    {
        result = sf::Color::White;
        break;
    }
    default:
    {
        result = sf::Color::Transparent;
        break;
    }
    }

    return result;
}

Map::Map(const sf::Vector2u& size):
    m_size(size)
{
    // 83
}

Map::~Map()
{

}

void Map::draw(Window* window)
{
    sf::RectangleShape unit(sf::Vector2f(UNIT_WIDTH, UNIT_HEIGHT));

    for (unsigned int row = 0; row < m_size.x; row++)
    {
        for (unsigned int col = 0; col < m_size.y; col++)
        {
            numToColorConverter(((col % 2 == 0) ? col : 7 - col));
            unit.setFillColor(numToColorConverter(((row % 2 == 0) ? col : 7 - col)));
            unit.setPosition(sf::Vector2f(col * UNIT_WIDTH, row * UNIT_HEIGHT));

            window->draw(unit);
        }
    }
}

void Map::drawFOV(Window* window, const sf::Vector2f& playerPixelPos)
{
    sf::RectangleShape unit(sf::Vector2f(UNIT_WIDTH, UNIT_HEIGHT));
    unit.setFillColor(sf::Color::Green);

    sf::Vector2i playerUnitPos = sf::Vector2i(playerPixelPos.x / UNIT_WIDTH, 
                                              playerPixelPos.y / UNIT_HEIGHT);

    //std::cout << "Player UP = " << playerUnitPos.x << " : " << playerUnitPos.y << ";\n";

    sf::Vector2u start;
    start.x = (playerUnitPos.x - 1 >= 0) ? playerUnitPos.x - 1 : 0 ;
    start.y = (playerUnitPos.y - 1 >= 0) ? playerUnitPos.y - 1 : 0 ;

    //std::cout << "Start UP = " << start.x << " : " << start.y << ";\n";

    sf::Vector2u end;
    end.x = (playerUnitPos.x + 1 < m_size.x) ? playerUnitPos.x + 1 : m_size.x - 1;
    end.y = (playerUnitPos.y + 1 < m_size.y) ? playerUnitPos.y + 1 : m_size.y - 1;

    //std::cout << "End UP = " << end.x << " : " << end.y << ";\n";

    //std::cout << "Map US = " << m_size.x << " : " << m_size.y << ";\n";

    for (unsigned int row = start.y; row <= end.y; row++)
    {
        for (unsigned int col = start.x; col <= end.x; col++)
        {
            unit.setPosition(sf::Vector2f(col * UNIT_WIDTH, row * UNIT_HEIGHT));

            window->draw(unit);
        }
    }
}