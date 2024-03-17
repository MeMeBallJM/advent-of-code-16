#include <array>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

struct Room {
    std::string name;
    int id;
};

int main(int argc, char const *argv[]) {
    std::ifstream file("puzzle_input.txt");

    std::vector<Room> rooms;

    std::string line;
    while (file >> line) {
        int lineIndex = 1;
        char character = line[0];

        std::string room_name = "";
        std::array<int, 27> letterCounts = {0};
        while (!isdigit(character)) {
            if (isalpha(character)) {
                letterCounts[character - 'a'] += 1;
                room_name.push_back(character);
            } else {
                room_name.push_back(' ');
            }

            character = line[lineIndex];
            lineIndex += 1;
        }
        room_name.pop_back();

        int id = 0;
        while (isdigit(character)) {
            id *= 10;
            id += character - '0';
            character = line[lineIndex];
            lineIndex += 1;
        }
        character = line[lineIndex];

        bool real = true;
        for (size_t i = 0; i < 5; i++) {
            int maxIndex = 0;
            for (size_t i = 1; i < 27; i++) {
                if (letterCounts[i] > letterCounts[maxIndex]) {
                    maxIndex = i;
                }
            }

            if (character - 'a' == maxIndex) {
                letterCounts[maxIndex] = 0;
                lineIndex += 1;
                character = line[lineIndex];
            } else {
                real = false;
            }
        }

        if (real) {
            rooms.push_back({
                room_name,
                id,
            });
        }
    }

    for (auto &room : rooms) {
        for (size_t i = 0; i < room.name.length(); i++) {
            if (room.name[i] == ' ') {
                continue;
            }
            room.name[i] = (room.name[i] - 'a' + room.id) % 26 + 'a';
        }
    }

    for (auto room : rooms) {
        std::cout << room.name << " : " << room.id << "\n";
    }
}
