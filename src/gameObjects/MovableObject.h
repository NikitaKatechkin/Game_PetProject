#ifndef MOVABLEOBJECTS_H
#define MOVABLEOBJECTS_H

#include <SFML/Graphics.hpp>

class MovableObject
{
public:
    MovableObject(sf::Sprite* sprite);
    ~MovableObject() = default;

public:
    void moveOn(const sf::Vector2f& direction);
    void moveTo(const sf::Vector2f& position);

public:
    sf::Vector2f getPosition();

protected:
    sf::Sprite* m_sprite = nullptr;
};

#endif
