#include <SFML/Graphics.hpp>

#include "window/Window.h"

int main()
{
    Window window;
    sf::CircleShape shape(100.f);
    
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        window.updateInput();

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}