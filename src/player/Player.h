#ifndef PLAYER_H
#define PLAYER_H

#include "../gameObjects/GameObject.h"
#include "../gameObjects/MovableObject.h"
#include "../gameObjects/HandlingObject.h"

class Player : public GameObject,
               public MovableObject,
               public HandlingObject
{
public:
    Player();
    ~Player() = default;

public:
    void handleEvents(EventQueue queue) override;
};

#endif