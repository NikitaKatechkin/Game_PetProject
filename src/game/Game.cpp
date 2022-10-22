#include "Game.h"

#include <iostream>

Game::Game()
{
    player.setSize(sf::Vector2u(32, 32));
    player.setTextureAsset("..\\..\\assets\\images\\Male\\Male_01-1.png");
    player.update();
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

void Game::handleEvents(EventQueue& queue)
{
    if (queue.empty() == false)
    {
        sf::Event event = queue.front();

        if (event.type == sf::Event::Closed)
        {
            m_isRunning = false;
        }
    }
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
        this->handleEvents(eventQueue);

        // Rendering stuff
        m_window->clear();
        
        m_window->draw(player.getSprite());

        m_window->display();
    }

    delete m_window;
}