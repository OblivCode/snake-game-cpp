#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>
#include "../game/snake.h"

class GameWindow
{
    public:
        GameWindow(int gameWidth, int gameHeight, int windowWidth = 800, int windowHeight = 600);
        void HandleEvents();
        void Render(Snake& snake);
        void Clear(const sf::Color& color);
        bool IsOpen() const;

        string GetDirection() const;

    private:
        sf::RenderWindow window;
        sf::View gameView;
        string direction;
        // up,down,left,right
        
        void HandleInput(sf::Event::KeyEvent key, bool isPressed);
};

#endif // WINDOW_H