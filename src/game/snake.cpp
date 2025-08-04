#include "snake.h"

Snake::Snake(int x, int y) {
    // Initialize snake with starting position
    body.push_back(make_tuple(x, y));
}

void Snake::Move(int x, int y) {
    tuple<int, int> current_pos = body.front();
    int new_x = get<0>(current_pos) + x;
    int new_y = get<1>(current_pos) + y;

    // Update the head position
    body.insert(body.begin(), make_tuple(new_x, new_y));

    // Remove the last segment to simulate movement
    if (body.size() > 1) {
        body.pop_back();
    }
}

vector<tuple<int, int>> Snake::GetBody() const {
    return body;
}