#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>

struct WindowContext
{
    sf::Vector2u size;
    sf::String title;
};

class Window
{
public:
    Window(const WindowContext& context = {sf::Vector2u(200, 400), "SFML Window"});
    ~Window();

public:
    void clear();
    void draw(const sf::Drawable& drawableObject);
    void display();

public:
    bool isOpen();
    void close();

public:
    bool togleWindowContext(bool value);

public:
    void resize(const sf::Vector2u& newSize);
    sf::Vector2u getSize();
    WindowContext getContext();

public:
    void updateInput();

public:
    void updateContext(const WindowContext& context);
    void refreshWindow();

private:
    sf::RenderWindow* m_renderWindow = nullptr;
    WindowContext m_context;
    sf::Event m_event;

private:
    bool isRenderWindowPtrValid();
};

#endif