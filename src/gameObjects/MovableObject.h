#ifndef MOVABLEOBJECT_H
#define MOVABLEOBJECT_H

#include <SFML/Graphics.hpp>

class MovableObject
{
public:
    MovableObject(sf::Sprite* sprite = nullptr);
    ~MovableObject() = default;

public:
    void moveOn(const sf::Vector2f& direction);
    void moveTo(const sf::Vector2f& position);

public:
    sf::Vector2f getPosition();
    void setMovableSprite(sf::Sprite* sprite);

private:
    sf::Sprite* m_spritePtr = nullptr;
};

#endif
