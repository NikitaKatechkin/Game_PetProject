#include "Window.h"

Window::Window()
{
    updateContext({sf::Vector2u(200, 400), "SFML Window"});
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
