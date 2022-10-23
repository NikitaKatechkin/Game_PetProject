#include "MovableObject.h"

MovableObject::MovableObject(sf::Sprite* sprite):
    m_sprite(sprite)
{

}

void MovableObject::moveOn(const sf::Vector2f& direction)
{
    m_sprite->setPosition(getPosition() + direction);
}

void MovableObject::moveTo(const sf::Vector2f& position)
{
    m_sprite->setPosition(position);
}

sf::Vector2f MovableObject::getPosition()
{
    return m_sprite->getPosition();
}

