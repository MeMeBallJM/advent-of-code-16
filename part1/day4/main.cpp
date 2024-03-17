#include <array>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int main(int argc, char const *argv[]) {
    std::ifstream file("puzzle_input.txt");

    int true_id = 0;

    std::string line;
    while (file >> line) {
        int lineIndex = 1;
        char character = line[0];

        std::array<int, 26> letterCounts = {0};
        while (!isdigit(character)) {
            if (isalpha(character)) {
                letterCounts[character - 'a'] += 1;
            }
            character = line[lineIndex];
            lineIndex += 1;
        }

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
            for (size_t i = 1; i < 26; i++) {
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

        true_id += real ? id : 0;
    }

    std::cout << true_id;
}
