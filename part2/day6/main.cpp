#include <array>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

template <size_t N>
size_t min(std::array<size_t, N> list) {
    size_t min = 0;
    for (size_t i = 0; i < N; i++) {
        if (list[i] < list[min] && list[i] != 0) {
            min = i;
        }
    }
    return min;
}

int main(int argc, char const* argv[]) {
    const constexpr size_t LINE_SIZE = 8;
    const constexpr size_t ALPHABET_LENGTH = 26;

    std::ifstream file("puzzle_input.txt");

    std::array<std::array<size_t, ALPHABET_LENGTH>, LINE_SIZE> columns = {0};

    std::string line;
    while (file >> line) {
        for (size_t i = 0; i < LINE_SIZE; i++) {
            columns[i][line[i] - 'a'] += 1;
        }
    }

    for (auto& column : columns) {
        std::cout << (char)(min(column) + 'a');
    }

    return 0;
}
