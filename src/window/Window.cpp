#include "Window.h"

#include <iostream>

Window::Window(const WindowContext& context)
{
    updateContext(context);
    refreshWindow();
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

bool Window::togleWindowContext(bool value)
{
    return m_renderWindow->setActive(value);
}

EventQueue Window::getEventQueue()
{
    sf::Event event;
    EventQueue eventQueue;

    while (m_renderWindow->pollEvent(event))
    {
        eventQueue.push(event);
    }

    return eventQueue;
}

void Window::resize(const sf::Vector2u& newSize)
{
    if (!isRenderWindowPtrValid()) 
    {
        return;
    }

    m_context.size = newSize;
    refreshWindow();
}

sf::Vector2u Window::getSize()
{
    if (!isRenderWindowPtrValid()) 
    {
        return sf::Vector2u();
    }

    return m_context.size;
}

WindowContext Window::getContext()
{
    return m_context;
}

void Window::handleEvents(EventQueue& queue)
{
    if (queue.empty() == false)
    {
        sf::Event event = queue.front();

        if (event.type == sf::Event::Closed)
        {
            close();
        }

        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::R)
            {
                resize(sf::Vector2u(m_context.size.y, m_context.size.x));
            }
        }
    }
}

void Window::updateContext(const WindowContext& context)
{
    m_context = context;
}

bool Window::isRenderWindowPtrValid()
{
    return m_renderWindow != nullptr;
}

void Window::refreshWindow()
{
    if (isRenderWindowPtrValid() == true)
    {
        delete m_renderWindow;
        m_renderWindow = nullptr;
    }

    m_renderWindow = new sf::RenderWindow(sf::VideoMode(m_context.size.x, m_context.size.y), 
                                          m_context.title);
}
