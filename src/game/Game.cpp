#include "Game.h"

#include <iostream>

Game::Game()
{

}

Game::~Game()
{
    if (m_executionThread.joinable())
    {
        m_executionThread.join();
    }
}

void Game::start(const WindowContext& context)
{
    m_isRunning = true;
    m_executionThread = std::thread(&Game::run, this, std::ref(context));
}

void Game::stop()
{
    m_isRunning = false;
    m_executionThread.join();
}

void Game::initWindow(const WindowContext& context)
{
    m_window = new Window(context);
}

void Game::run(const WindowContext& context)
{
    initWindow(context);

    while (m_isRunning == true)
    {
        // Fill the event
        EventQueue eventQueue = m_window->getEventQueue();

        // All memebers handle the event
        m_window->handleEvents(eventQueue);

        // Rendering stuff

        m_window->clear();
        //m_window.draw();
        m_window->display();

        if (m_window->isOpen() == false)
        {
            m_isRunning = false;
        }
    }

    delete m_window;
}