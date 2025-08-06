#include <SFML/Graphics.hpp>
#include <vector>
#include <tuple>
#include "ui/window.h"
#include <thread>
#include <chrono>

using namespace std;

int main()
{
    // Create window with 40x40 game resolution but 800x600 actual window size
    GameWindow window(150, 150, 800, 600);
    Snake snake(10, 10);  // Create a snake instance at position (10, 10)

    // Main game loop
    while (window.IsOpen())
    {
        //auto delay = std::chrono::
        std::this_thread::sleep_for(30ms);
        // Event handling
        window.HandleEvents();
        // Direction handling
        string direction = window.GetDirection();
        if(direction == "up") {
            snake.Move(0, -1);
        } else if(direction == "down") {
            snake.Move(0, 1);
        } else if (direction == "left")
            snake.Move(-1,0);
        else if (direction == "right")
            snake.Move(1,0);

        window.Clear(sf::Color(0,0,0)); // Clear the screen with a color (dark grey)
        
        // Update the window
        window.Render(snake);
    }

    return 0;
}