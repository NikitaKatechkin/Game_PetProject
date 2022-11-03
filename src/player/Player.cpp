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
                moveOn(sf::Vector2f(32, 0));
                
                break;
            }
            case sf::Keyboard::Left:
            {
                moveOn(sf::Vector2f(-32, 0));
                
                break;
            }
            case sf::Keyboard::Up:
            {
                moveOn(sf::Vector2f(0, -32));
                
                break;
            }
            case sf::Keyboard::Down:
            {
                moveOn(sf::Vector2f(0, 32));
                
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

sf::Vector2i Player::getUnitPosition()
{
    sf::Vector2f currentPos = getPosition();
    return sf::Vector2i(currentPos.x / UNIT_WIDTH, currentPos.y / UNIT_HEIGHT);
}