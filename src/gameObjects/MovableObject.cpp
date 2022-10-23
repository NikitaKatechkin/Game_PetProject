#include "MovableObject.h"

MovableObject::MovableObject():
    GameObject()
{

}

void MovableObject::moveOn(const sf::Vector2f& direction)
{
    m_sprite.setPosition(m_sprite.getPosition() + direction);
}

void MovableObject::moveTo(const sf::Vector2f& position)
{
    m_sprite.setPosition(position);
}

sf::Vector2f MovableObject::getPosition()
{
    return m_sprite.getPosition();
}

