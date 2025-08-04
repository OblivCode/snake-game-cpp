#include <SFML/Graphics.hpp>
#include <vector>
#include <tuple>
#include "ui/window.h"

using namespace std;

int main()
{
    GameWindow window;
    Snake snake(10, 10);  // Create a snake instance at position (10, 10)

    // Main game loop
    while (window.isOpen())
    {
        // Event handling
        window.HandleEvents();

        window.Clear(sf::Color(0,0,0)); // Clear the screen with a color (dark grey)
        
        // Update the window
        window.Render(snake);
    }

    return 0;
}