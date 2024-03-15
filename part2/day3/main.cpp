#include <fstream>
#include <iostream>
#include <vector>

int main(int argc, char const *argv[]) {
    std::ifstream file("puzzle_input.txt");

    int count = 0;

    while (file.get() != EOF) {
        int t1[3] = {0};
        int t2[3] = {0};
        int t3[3] = {0};

        for (size_t i = 0; i < 3; i++) {
            file >> t1[i];
            file >> t2[i];
            file >> t3[i];
        }

        if (t1[0] + t1[1] > t1[2] && t1[0] + t1[2] > t1[1] &&
            t1[1] + t1[2] > t1[0]) {
            count++;
        }

        if (t2[0] + t2[1] > t2[2] && t2[0] + t2[2] > t2[1] &&
            t2[1] + t2[2] > t2[0]) {
            count++;
        }

        if (t3[0] + t3[1] > t3[2] && t3[0] + t3[2] > t3[1] &&
            t3[1] + t3[2] > t3[0]) {
            count++;
        }
    }

    printf("%i\n", count);

    return 0;
}
