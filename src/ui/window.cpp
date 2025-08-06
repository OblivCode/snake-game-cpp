#include "window.h"
#include "vector"
#include <iostream>

using namespace std;

GameWindow::GameWindow(int gameWidth, int gameHeight, int windowWidth, int windowHeight) 
    : window(sf::VideoMode(windowWidth, windowHeight), "Snake Game") {
    direction = "right";
    
    // Create a view with the low resolution game size
    gameView.reset(sf::FloatRect(0, 0, gameWidth, gameHeight));
    window.setView(gameView);
}

void GameWindow::HandleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        else if (event.type == sf::Event::KeyPressed) {
            HandleInput(event.key, true);  // true = key pressed
        }
        else if (event.type == sf::Event::KeyReleased) {
            HandleInput(event.key, false); // false = key released
        }
    }
}

void GameWindow::Render(Snake& snake) {
    // Render the snake
    for (const tuple<int, int>& segment : snake.GetBody()) {
        sf::RectangleShape rectangle(sf::Vector2f(10, 10));
        rectangle.setPosition(get<0>(segment), get<1>(segment));
        window.draw(rectangle);
    }
    window.display();
}

void GameWindow::Clear(const sf::Color& color) {
    window.clear(color);
}

bool GameWindow::IsOpen() const {
    return window.isOpen();
}

void GameWindow::HandleInput(sf::Event::KeyEvent key, bool isPressed) {
    if (isPressed) {
        // Handle key press
        auto code = key.code;
        if(code == sf::Keyboard::Up) {
            direction = "up";
        }
        else if(code == sf::Keyboard::Down) {
            direction = "down";
        }
        else if(code == sf::Keyboard::Left) {
            direction = "left";
        }
        else if(code == sf::Keyboard::Right) {
            direction = "right";
        }
    } 
}

string GameWindow::GetDirection() const {
    return direction;
}

