#include <fstream>
#include <iostream>
#include <string>

struct KeyPadPos {
    int x;
    int y;

    void left() {
        int new_x = x - 1;
        if (new_x * new_x + y * y <= 4) {
            x = new_x;
        }
    }

    void right() {
        int new_x = x + 1;
        if (new_x * new_x + y * y <= 4) {
            x = new_x;
        }
    }

    void up() {
        int new_y = y - 1;
        if (new_y * new_y + x * x <= 4) {
            y = new_y;
        }
    }

    void down() {
        int new_y = y + 1;
        if (new_y * new_y + x * x <= 4) {
            y = new_y;
        }
    }
};

int main(int argc, char const *argv[]) {
    std::ifstream file("puzzle_input.txt");

    KeyPadPos position = {-2, 0};

    std::string line;
    while (std::getline(file, line)) {
        for (char &c : line) {
            switch (c) {
                case 'L':
                    position.left();
                    break;
                case 'R':
                    position.right();
                    break;
                case 'U':
                    position.up();
                    break;
                case 'D':
                    position.down();
                    break;
            }
        }

        switch (position.y) {
            case -2:
                printf("%x", 1);
                break;
            case -1:
                printf("%x", 3 + position.x);
                break;
            case 0:
                printf("%x", 7 + position.x);
                break;
            case 1:
                printf("%x", 11 + position.x);
                break;
            case 2:
                printf("%x", 13);
                break;
        }
    }

    return 0;
}
