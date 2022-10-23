#include "Player.h"

Player::Player():
    GameObject(), MovableObject(), HandlingObject()
{
    this->setMovableSprite(&m_sprite);
};

void Player::handleEvents(EventQueue& events)
{

}