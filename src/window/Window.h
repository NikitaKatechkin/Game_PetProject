#include <SFML/Graphics.hpp>

class Window
{
public:
    Window();
    ~Window();

public:
    void clear();
    void draw(const sf::Drawable& drawableObject);
    void display();

public:
    bool isOpen();
    void close();

public:
    void resize(const sf::Vector2u& newSize);
    sf::Vector2u getSize();

public:
    void updateInput();

private:
    sf::RenderWindow* m_renderWindow = nullptr;
    sf::Event m_event;

private:
    bool isRenderWindowPtrValid();
};