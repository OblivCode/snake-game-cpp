#include "window.h"
#include "vector"

GameWindow::GameWindow() {
    // Initialise the window
    window.create(sf::VideoMode(800, 600), "Snake Game");
}

void GameWindow::HandleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void GameWindow::Render(Snake& snake) {
    // Render the snake
    for (const tuple<int, int>& segment : snake.GetBody()) {
        sf::RectangleShape rectangle(sf::Vector2f(10, 10));
        rectangle.setPosition(get<0>(segment), get<1>(segment));
        window.draw(rectangle);
    }
}