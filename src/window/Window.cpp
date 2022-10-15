#include "Window.h"

Window::Window():
    m_renderWindow(new sf::RenderWindow(sf::VideoMode(200, 400), "SFML works!"))
{
    
}

Window::~Window()
{
    if (isRenderWindowPtrValid()) 
    {
        delete m_renderWindow; 
        m_renderWindow = nullptr;
    }
}

void Window::clear()
{
    if (!isRenderWindowPtrValid()) 
    {
        return;
    }

    m_renderWindow->clear();
}

void Window::draw(const sf::Drawable& drawableObject)
{
    if (!isRenderWindowPtrValid()) 
    {
        return;
    }
    
    m_renderWindow->draw(drawableObject);
}

void Window::display()
{
    if (!isRenderWindowPtrValid()) 
    {
        return;
    }

    m_renderWindow->display();
}

bool Window::isOpen()
{
    if (!isRenderWindowPtrValid()) 
    {
        return false;
    }

    return m_renderWindow->isOpen();
}

void Window::close()
{
    if (!isRenderWindowPtrValid()) 
    {
        return;
    }

    return m_renderWindow->close();
}

void Window::resize(const sf::Vector2u& newSize)
{
    if (!isRenderWindowPtrValid()) 
    {
        return;
    }

    delete m_renderWindow;
    m_renderWindow = new sf::RenderWindow(sf::VideoMode(newSize.x, newSize.y), "SFML works!");
}

sf::Vector2u Window::getSize()
{
    if (!isRenderWindowPtrValid()) 
    {
        return sf::Vector2u();
    }

    return m_renderWindow->getSize();
}

void Window::updateInput()
{
    if (!isRenderWindowPtrValid()) 
    {
        return;
    }

    while (m_renderWindow->pollEvent(m_event))
    {
        if (m_event.type == sf::Event::Closed)
            close();
        
        if (m_event.type == sf::Event::KeyPressed)
        {
            if (m_event.key.code == sf::Keyboard::R)
            {
                sf::Vector2u oldSize = getSize();
                resize(sf::Vector2u(oldSize.y, oldSize.x));
            }
        }
    }
}

bool Window::isRenderWindowPtrValid()
{
    return m_renderWindow != nullptr;
}