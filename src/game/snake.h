#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <tuple>

using namespace std;

class Snake
{
    public:
        // Constructor to initialize the snake at a specific position
        Snake(int x, int y); 
        void Move(int x, int y); // -1 for left, 1 for right, -1 for up, 1 for down
        vector<tuple<int, int>> GetBody() const { return body; } // Function to get the snake's body segments
    private:
        // Vector to hold the snake's body segments
        vector<tuple<int, int>> body; 
};

#endif // SNAKE_H