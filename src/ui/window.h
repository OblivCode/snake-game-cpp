#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>
#include "../game/snake.h"

class GameWindow
{
    public:
        GameWindow();
        void HandleEvents();
        void Render(Snake& snake);
        void Clear(const sf::Color& color) { window.clear(color); }
        bool isOpen() const { return window.isOpen(); }

    private:
        sf::RenderWindow window;
};

#endif // WINDOW_H