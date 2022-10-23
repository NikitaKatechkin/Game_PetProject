#ifndef MOVABLEOBJECTS_H
#define MOVABLEOBJECTS_H

#include "GameObject.h"

class MovableObject : public GameObject
{
public:
    MovableObject();
    ~MovableObject() = default;

public:
    void moveOn(const sf::Vector2f& direction);
    void moveTo(const sf::Vector2f& position);

public:
    sf::Vector2f getPosition();
};

#endif
