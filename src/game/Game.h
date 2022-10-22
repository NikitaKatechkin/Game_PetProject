#ifndef GAME_H
#define GAME_H

#include "../window/Window.h"
#include "../gameObjects/GameObject.h"

#include <thread>

class Game
{
public:
    Game();
    ~Game();

public:
    void start(const WindowContext& context = {sf::Vector2u(400, 400), "SFML Window"});
    void stop();

    void handleEvents(EventQueue& queue);

private:
    void initWindow(const WindowContext& context);
    void run(const WindowContext& context);

private:
    Window* m_window = nullptr;

    std::thread m_executionThread;
    bool m_isRunning = false;
};

#endif