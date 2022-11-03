#ifndef CAMERA_H
#define CAMERA_H

#include <SFML/Graphics.hpp>

class Camera
{
public:
    Camera(const sf::Vector2u& mapSize = sf::Vector2u(0, 0));
    ~Camera();

public:
    void blackOut();
    void updateFOV(const sf::Vector2i& playerUnitPos);

public:
    std::vector<sf::Drawable*>& getView();

private:
    sf::Vector2u m_mapSize;
    std::vector<sf::Drawable*> m_view;
};

#endif