#include <array>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "md5.h"

int main(int argc, char const *argv[]) {
    std::string base("uqwqemis");

    std::string password("");

    for (size_t i = 0; password.length() < 8; i++) {
        std::string to_hash = base + std::to_string(i);
        std::string hashed = md5(to_hash);

        if (hashed[0] == '0' && hashed[1] == '0' && hashed[2] == '0' &&
            hashed[3] == '0' && hashed[4] == '0') {
            password.push_back(hashed[5]);
            std::cout << password << '\n';
        }
    }

    std::cout << password;

    return 0;
}
