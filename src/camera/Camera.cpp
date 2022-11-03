#include "Camera.h"
#include "../constants/GameConstants.h"

Camera::Camera(const sf::Vector2u& mapSize):
    m_mapSize(mapSize)
{
    for (unsigned int row = 0; row < m_mapSize.y; row++)
    {
        for (unsigned int col = 0; col < m_mapSize.x; col++)
        {
            m_view.push_back(new sf::RectangleShape());
            sf::RectangleShape* unit = reinterpret_cast<sf::RectangleShape*>(m_view[row * m_mapSize.x + col]);

            unit->setPosition(sf::Vector2f(col * UNIT_WIDTH, row * UNIT_HEIGHT));
            unit->setSize(sf::Vector2f(UNIT_WIDTH, UNIT_HEIGHT));
            unit->setFillColor(sf::Color::Black);
        }
    }
}

Camera::~Camera()
{

}

void Camera::blackOut()
{
    for (unsigned int row = 0; row < m_mapSize.y; row++)
    {
        for (unsigned int col = 0; col < m_mapSize.x; col++)
        {
            sf::RectangleShape* unit = reinterpret_cast<sf::RectangleShape*>(m_view[row * m_mapSize.x + col]);
            
            unit->setFillColor(sf::Color::Black);
        }
    }
}

void Camera::updateFOV(const sf::Vector2f& playerPixelPos)
{
    this->blackOut();

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
        ((playerUnitPos.x + 1 < static_cast<int>(m_mapSize.x)) ? playerUnitPos.x + 1 : m_mapSize.x - 1),
        ((playerUnitPos.y + 1 < static_cast<int>(m_mapSize.y)) ? playerUnitPos.y + 1 : m_mapSize.y - 1)
    );

    //std::cout << "Player UP = " << playerUnitPos.x << " : " << playerUnitPos.y << ";\n";
    //std::cout << "Start UP = " << start.x << " : " << start.y << ";\n";
    //std::cout << "End UP = " << end.x << " : " << end.y << ";\n";
    //std::cout << "Map US = " << m_size.x << " : " << m_size.y << ";\n";

    for (int row = start.y; row <= end.y; row++)
    {
        for (int col = start.x; col <= end.x; col++)
        {
            sf::RectangleShape* unit = reinterpret_cast<sf::RectangleShape*>(m_view[row * m_mapSize.x + col]);

            unit->setFillColor(sf::Color::Transparent);
        }
    }
}

std::vector<sf::Drawable*>& Camera::getView()
{
    return m_view;
}
