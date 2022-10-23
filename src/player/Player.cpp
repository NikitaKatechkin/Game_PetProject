#include "Player.h"

Player::Player():
    GameObject(), MovableObject(), HandlingObject()
{
    this->setMovableSprite(&m_sprite);
};

void Player::handleEvents(EventQueue queue)
{
    for(size_t i = 0; i < queue.size(); i++)
    {
        sf::Event event = queue.front();

        if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
            case sf::Keyboard::Right:
            {
                moveOn(sf::Vector2f(5, 0));
                
                break;
            }
            case sf::Keyboard::Left:
            {
                moveOn(sf::Vector2f(-5, 0));
                
                break;
            }
            case sf::Keyboard::Up:
            {
                moveOn(sf::Vector2f(0, -5));
                
                break;
            }
            case sf::Keyboard::Down:
            {
                moveOn(sf::Vector2f(0, 5));
                
                break;
            }
            default:
            {
                break;
            }
            }
        }

        queue.pop();
    }
}