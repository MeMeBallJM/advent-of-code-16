#include <fstream>
#include <iostream>
#include <string>

struct KeyPadPos {
    int x;
    int y;

    void left() { x = x > 0 ? x - 1 : x; }
    void right() { x = x < 2 ? x + 1 : x; }
    void up() { y = y > 0 ? y - 1 : y; }
    void down() { y = y < 2 ? y + 1 : y; }
};

int main(int argc, char const *argv[]) {
    std::ifstream file("puzzle_input.txt");

    KeyPadPos position = {1, 1};

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

        std::cout << (position.x + 3 * position.y + 1);
    }

    std::cout << '\n';

    return 0;
}
