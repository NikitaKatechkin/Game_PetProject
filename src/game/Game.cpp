#include "Game.h"

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

void Game::Start(const WindowContext& context)
{
    m_isRunning = true;
    m_executionThread = std::thread(&Game::Run, this, std::ref(context));
}

void Game::Stop()
{
    m_isRunning = false;
    m_executionThread.join();
}

void Game::InitWindow(const WindowContext& context)
{
    m_window = new Window(context);
}

void Game::Run(const WindowContext& context)
{
    InitWindow(context);

    while (m_isRunning == true)
    {
        m_window->updateInput();

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