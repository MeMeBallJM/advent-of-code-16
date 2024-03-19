#include <array>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

bool is_abba(std::string text) {
    if (text.length() < 4) {
        return false;
    }

    for (size_t i = 0; i < text.length() - 3; i++) {
        if (text[i] == text[i + 3] && text[i + 1] == text[i + 2] &&
            text[i] != text[i + 1]) {
            return true;
        }
    }
    return false;
}

bool is_ssl(std::string text) {
    if (text.length() < 3) {
        return false;
    }

    for (size_t i = 0; i < text.length() - 2; i++) {
        if (text[i] == text[i + 2] && text[i] != text[i + 1]) {
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[]) {
    std::ifstream file("puzzle_input.txt");

    size_t ip_count = 0;

    std::string line;
    while (file >> line) {
        bool vaild_ip = false;
        bool unwanted_abba = false;
        bool wanted_abba = false;

        bool abba_wanted = true;
        std::replace(line.begin(), line.end(), '[', '|');
        std::replace(line.begin(), line.end(), ']', '|');
        line.push_back('|');

        while (line.length() != 0) {
            size_t swap_index = line.find('|');
            std::string chunk = line.substr(0, swap_index);

            if (is_abba(chunk) && abba_wanted) {
                wanted_abba = true;
            } else if (is_abba(chunk) && !abba_wanted) {
                unwanted_abba = true;
            }

            abba_wanted = !abba_wanted;
            line.erase(line.begin(), line.begin() + swap_index + 1);
        }
        vaild_ip = wanted_abba && !unwanted_abba;
        ip_count += vaild_ip ? 1 : 0;
    }

    std::cout << ip_count << '\n';

    return 0;
}
