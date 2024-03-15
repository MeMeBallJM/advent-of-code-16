#include <fstream>
#include <iostream>
#include <tuple>
#include <vector>

struct Position {
    int x;
    int y;
};

struct Player {
    Position pos;
    int direction;

    void walkForward(int stepCount, std::vector<Position> &visited) {
        for (size_t i = 0; i < stepCount; i++) {
            switch (direction) {
                case 0:
                    pos.x += 1;
                    break;
                case 1:
                    pos.y += 1;
                    break;
                case 2:
                    pos.x -= 1;
                    break;
                case 3:
                    pos.y -= 1;
                    break;
            }

            for (auto &position : visited) {
                if (position.x == pos.x && position.y == pos.y) {
                    printf("x: %i, y: %i\n", pos.x, pos.y);
                }
            }

            visited.push_back(pos);
        }
    }

    void turnLeft() { direction = (direction + 1) % 4; }
    void turnRight() { direction = (direction + 3) % 4; }
};

int main(int argc, char const *argv[]) {
    std::ifstream file("puzzle_input.txt");

    Player player = {0, 0, 1};

    std::vector<Position> visited;
    visited.push_back(player.pos);

    char character = file.get();
    int currentStepCount = 0;
    while (character != EOF) {
        if (character == 'R') {
            player.turnRight();
        } else if (character == 'L') {
            player.turnLeft();
        }

        if (!isdigit(character) && currentStepCount != 0) {
            player.walkForward(currentStepCount, visited);
            currentStepCount = 0;
        }

        if (isdigit(character)) {
            currentStepCount *= 10;
            currentStepCount += (int)(character - '0');
        }

        character = file.get();
    }

    return 0;
}
