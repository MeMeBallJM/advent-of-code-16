#include <array>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

size_t read_int_cut(std::string& str, size_t extra_cut) {
    size_t n = 0;
    size_t cut_size = 0;
    for (size_t i = 0; isdigit(str[i]); i++) {
        n *= 10;
        n += str[i] - '0';
        cut_size = i;
    }

    str.erase(str.begin(), str.begin() + cut_size + extra_cut + 1);
    return n;
}

int main(int argc, char const* argv[]) {
    std::ifstream file("puzzle_input.txt");
    std::string line;
    getline(file, line);

    std::string uncompressed = "";

    while (line.find('(') != std::string::npos) {
        size_t marker = line.find('(');
        std::string before_marker = line.substr(0, marker);
        uncompressed += before_marker;
        line.erase(0, marker + 1);
        size_t window_size = read_int_cut(line, 1);
        size_t repeat_size = read_int_cut(line, 1);
        std::string repeat = line.substr(0, window_size);
        line.erase(0, window_size);

        for (size_t i = 0; i < repeat_size; i++) {
            uncompressed += repeat;
        }
    }

    if (line.length() != 0) {
        uncompressed += line;
    }

    std::cout << uncompressed.length() << '\n';

    return 0;
}
