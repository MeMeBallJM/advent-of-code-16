#include <fstream>
#include <iostream>
#include <tuple>

struct Player {
    int x_pos;
    int y_pos;
    int direction;

    void walkForward(int stepCount) {
        switch (direction) {
            case 0:
                x_pos += stepCount;
                break;
            case 1:
                y_pos += stepCount;
                break;
            case 2:
                x_pos -= stepCount;
                break;
            case 3:
                y_pos -= stepCount;
                break;
        }
    }

    void turnLeft() { direction = (direction + 1) % 4; }
    void turnRight() { direction = (direction + 3) % 4; }
};

int main(int argc, char const *argv[]) {
    std::ifstream file("puzzle_input.txt");

    Player player = {0, 0, 1};

    char character = file.get();
    int currentStepCount = 0;
    while (character != EOF) {
        if (character == 'R') {
            player.turnRight();
        } else if (character == 'L') {
            player.turnLeft();
        }

        if (!isdigit(character)) {
            player.walkForward(currentStepCount);
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
