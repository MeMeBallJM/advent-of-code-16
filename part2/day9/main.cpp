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

size_t decompressed_length(std::string str) {
    if (str.find('(') == std::string::npos) {
        return str.length();
    }

    size_t before_marker = str.find('(');
    str.erase(0, before_marker + 1);

    size_t window_size = read_int_cut(str, 1);
    size_t repeat_size = read_int_cut(str, 1);

    std::string repeat = str.substr(0, window_size);

    size_t expanded_bracket_size = repeat_size * decompressed_length(repeat);

    std::string rest = str.substr(window_size, str.length());

    return before_marker + expanded_bracket_size + decompressed_length(rest);
}

int main(int argc, char const* argv[]) {
    std::ifstream file("puzzle_input.txt");
    std::string line;
    getline(file, line);

    std::cout << decompressed_length(line) << '\n';

    return 0;
}
