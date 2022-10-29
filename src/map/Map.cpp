#include "Map.h"

#include <iostream>
#include <fstream>
#include <array>
#include <sstream>

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
        result = sf::Color::Red;
        break;
    }
    }

    return result;
}

Map::Map(const std::string& configFilePath)
{
    Initialize(configFilePath);

    std::cout << "Map size: " << m_size.x << " : " << m_size.y << ";" << std::endl;
}

Map::~Map()
{

}

void Map::draw(Window* window)
{
    for (unsigned int row = 0; row < m_size.y; row++)
    {
        for (unsigned int col = 0; col < m_size.x; col++)
        {
            sf::RectangleShape* unit = reinterpret_cast<sf::RectangleShape*>(m_units[row * m_size.x + col]);
            
            window->draw(*unit);
        }
    }
}

void Map::drawFOV(Window* window, const sf::Vector2f& playerPixelPos)
{
    sf::RectangleShape unit(sf::Vector2f(UNIT_WIDTH, UNIT_HEIGHT));
    unit.setFillColor(sf::Color::Green);

    sf::Vector2i playerUnitPos = sf::Vector2i(
        playerPixelPos.x / UNIT_WIDTH, 
        playerPixelPos.y / UNIT_HEIGHT
    );

    sf::Vector2i start(
        ((playerUnitPos.x - 1 >= 0) ? playerUnitPos.x - 1 : 0), 
        ((playerUnitPos.y - 1 >= 0) ? playerUnitPos.y - 1 : 0)
    );

    sf::Vector2i end(
        ((playerUnitPos.x + 1 < static_cast<int>(m_size.x)) ? playerUnitPos.x + 1 : m_size.x - 1),
        ((playerUnitPos.y + 1 < static_cast<int>(m_size.y)) ? playerUnitPos.y + 1 : m_size.y - 1)
    );

    //std::cout << "Player UP = " << playerUnitPos.x << " : " << playerUnitPos.y << ";\n";
    //std::cout << "Start UP = " << start.x << " : " << start.y << ";\n";
    //std::cout << "End UP = " << end.x << " : " << end.y << ";\n";
    //std::cout << "Map US = " << m_size.x << " : " << m_size.y << ";\n";

    for (int row = start.y; row <= end.y; row++)
    {
        for (int col = start.x; col <= end.x; col++)
        {
            unit.setPosition(sf::Vector2f(col * UNIT_WIDTH, row * UNIT_HEIGHT));

            window->draw(unit);
        }
    }
}

std::vector<sf::Drawable*>& Map::getDrawables()
{
    return m_units;
}

void Map::Initialize(const std::string& configFilePath)
{
    std::ifstream configFileStream(configFilePath);

    if (configFileStream.is_open() == true)
    {
        configFileStream >> m_size.x >> m_size.y;

        std::string mapRow;
        std::getline(configFileStream, mapRow);
        
        for (unsigned int row = 0; row < m_size.y; row++)
        {
            std::getline(configFileStream, mapRow);
            std::cout << mapRow << std::endl;

            for (unsigned int col = 0; col < m_size.x; col++)
            {
                m_units.push_back(new sf::RectangleShape());
                sf::RectangleShape* unit = reinterpret_cast<sf::RectangleShape*>(m_units[row * m_size.x + col]);

                unit->setPosition(sf::Vector2f(col * UNIT_WIDTH, row * UNIT_HEIGHT));
                unit->setSize(sf::Vector2f(UNIT_WIDTH, UNIT_HEIGHT));

                if (mapRow[col] == '#')
                {
                    unit->setFillColor(sf::Color::Blue);
                }
                else
                {
                    unit->setFillColor(sf::Color::White);
                }
            }
        }
    }
    else
    {
        std::cerr << "[Map::Initialize] " << "Failed to initialize map." << std::endl;
    }

    configFileStream.close();
}