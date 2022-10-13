#include "Window.h"

Window::Window()
{

}

Window::~Window()
{
    if (m_renderWindow != nullptr) 
    {
        delete m_renderWindow; 
        m_renderWindow = nullptr;
    }
}