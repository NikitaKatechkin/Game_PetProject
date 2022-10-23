#include "MovableObject.h"

MovableObject::MovableObject(sf::Sprite* sprite):
    m_spritePtr(sprite)
{

}

void MovableObject::moveOn(const sf::Vector2f& direction)
{
    m_spritePtr->setPosition(getPosition() + direction);
}

void MovableObject::moveTo(const sf::Vector2f& position)
{
    m_spritePtr->setPosition(position);
}

sf::Vector2f MovableObject::getPosition()
{
    return m_spritePtr->getPosition();
}

void MovableObject::setMovableSprite(sf::Sprite* sprite)
{
    m_spritePtr = sprite;
}

