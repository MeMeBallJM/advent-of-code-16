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

std::vector<std::string> ssl(std::string text) {
    if (text.length() < 3) {
        return std::vector<std::string>();
    }

    std::vector<std::string> babs;

    for (size_t i = 0; i < text.length() - 2; i++) {
        if (text[i] == text[i + 2] && text[i] != text[i + 1]) {
            std::string bab;
            bab.push_back(text[i + 1]);
            bab.push_back(text[i]);
            bab.push_back(text[i + 1]);
            babs.push_back(bab);
        }
    }
    return babs;
}

int main(int argc, char const *argv[]) {
    std::ifstream file("puzzle_input.txt");

    size_t ip_count = 0;

    std::string line;
    while (file >> line) {
        bool vaild_ip = false;
        bool unwanted_abba = false;
        bool wanted_abba = false;

        bool bracketed = false;
        std::replace(line.begin(), line.end(), '[', '|');
        std::replace(line.begin(), line.end(), ']', '|');
        line.push_back('|');

        std::vector<std::string> bracketed_chunks;
        std::vector<std::string> unbracketed_chunks;

        while (line.length() != 0) {
            size_t swap_index = line.find('|');
            std::string chunk = line.substr(0, swap_index);

            if (bracketed) {
                bracketed_chunks.push_back(chunk);
            } else {
                unbracketed_chunks.push_back(chunk);
            }

            if (is_abba(chunk) && !bracketed) {
                wanted_abba = true;
            } else if (is_abba(chunk) && bracketed) {
                unwanted_abba = true;
            }

            bracketed = !bracketed;
            line.erase(line.begin(), line.begin() + swap_index + 1);
        }

        std::vector<std::string> babs;
        for (const auto &x : unbracketed_chunks) {
            for (const auto &bab : ssl(x)) {
                babs.push_back(bab);
            }
        }

        bool bab_found = false;
        for (auto &chunk : bracketed_chunks) {
            for (auto &bab : babs) {
                if (chunk.find(bab) != std::string::npos) {
                    bab_found = true;
                }
            }
        }

        ip_count += bab_found ? 1 : 0;
    }

    std::cout << ip_count << '\n';
}
