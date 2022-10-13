#include <SFML/Graphics.hpp>

class Window
{
public:
    Window();
    ~Window();
private:
    sf::RenderWindow* m_renderWindow = nullptr;
};