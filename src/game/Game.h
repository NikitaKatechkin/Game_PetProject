#ifndef GAME_H
#define GAME_H

#include "../window/Window.h"

#include <thread>

class Game
{
public:
    Game();
    ~Game();

public:
    void Start(const WindowContext& context = {sf::Vector2u(400, 400), "SFML Window"});
    void Stop();

private:
    void InitWindow(const WindowContext& context);
    void Run(const WindowContext& context);

private:
    Window* m_window = nullptr;

    std::thread m_executionThread;
    bool m_isRunning = false;
};

#endif