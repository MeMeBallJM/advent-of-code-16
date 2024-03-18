#include <array>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "md5.h"

int main(int argc, char const *argv[]) {
    std::string base("uqwqemis");

    std::string password("        ");
    size_t count = 0;
    for (size_t i = 0; count < 8; i++) {
        std::string to_hash = base + std::to_string(i);
        std::string hashed = md5(to_hash);

        if (hashed[0] == '0' && hashed[1] == '0' && hashed[2] == '0' &&
            hashed[3] == '0' && hashed[4] == '0') {
            if (hashed[5] >= '0' && hashed[5] <= '7' &&
                password[hashed[5] - '0'] == ' ') {
                std::cout << hashed << '\n';
                password[hashed[5] - '0'] = hashed[6];
                count += 1;
            }
        }
    }

    std::cout << password;

    return 0;
}
