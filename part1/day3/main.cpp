#include <fstream>
#include <iostream>
#include <vector>

int main(int argc, char const *argv[]) {
    std::ifstream file("puzzle_input.txt");

    int count = 0;

    while (file) {
        int a, b, c;
        file >> a;
        file >> b;
        file >> c;

        std::string _line;
        getline(file, _line);

        printf("%i %i %i\n", a, b, c);

        if (b + c > a && a + c > b && a + b > c) {
            count++;
        }

        printf("%i\n", count);
    }
    return 0;
}
