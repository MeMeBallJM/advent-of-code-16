#include <array>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

struct rect_t {
    size_t x;
    size_t y;
};

struct rotation_t {
    size_t axis;
    size_t amount;
};

union action_data_t {
    rect_t rect;
    rotation_t down;
    rotation_t right;
};

enum action_type_t {
    Rectangle,
    Vertical,
    Horizontal,
};

struct action_t {
    action_data_t action;
    action_type_t type;
};

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

template <size_t W, size_t H>
void print_screen(std::array<std::array<bool, W>, H> screen) {
    for (size_t i = 0; i < H; i++) {
        for (size_t j = 0; j < W; j++) {
            std::cout << screen[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

template <size_t W, size_t H>
void light_rectangle(std::array<std::array<bool, W>, H>& screen, size_t width,
                     size_t height) {
    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++) {
            screen[i][j] = true;
        }
    }
}

template <size_t W, size_t H>
void rotate_horizontally(std::array<std::array<bool, W>, H>& screen, size_t row,
                         size_t amount) {
    for (size_t i = 0; i < amount; i++) {
        bool roll_over = screen[row][W - 1];
        for (size_t j = W - 1; j > 0; j--) {
            screen[row][j] = screen[row][j - 1];
        }
        screen[row][0] = roll_over;
    }
}

template <size_t W, size_t H>
void rotate_vertically(std::array<std::array<bool, W>, H>& screen,
                       size_t column, size_t amount) {
    for (size_t i = 0; i < amount; i++) {
        bool roll_over = screen[H - 1][column];
        for (size_t j = H - 1; j > 0; j--) {
            screen[j][column] = screen[j - 1][column];
        }
        screen[0][column] = roll_over;
    }
}

int main(int argc, char const* argv[]) {
    std::ifstream file("puzzle_input.txt");

    std::vector<action_t> actions;

    std::string line;
    while (getline(file, line)) {
        size_t space_index = line.find(' ');
        std::string action_name = line.substr(0, space_index);
        line.erase(line.begin(), line.begin() + space_index + 1);

        if (action_name == "rect") {
            action_t action;
            action.type = action_type_t::Rectangle;
            size_t x = read_int_cut(line, 1);
            size_t y = read_int_cut(line, 0);
            action.action.rect = (rect_t){.x = x, .y = y};
            actions.push_back(action);
            continue;
        }

        if (action_name == "rotate") {
            size_t end_of_dir = line.find(' ');
            std::string direction = line.substr(0, end_of_dir);
            line.erase(line.begin(), line.begin() + end_of_dir + 3);

            if (direction == "column") {
                action_t action;
                action.type = action_type_t::Vertical;
                size_t column = read_int_cut(line, 4);
                size_t amount = read_int_cut(line, 0);
                action.action.down =
                    (rotation_t){.axis = column, .amount = amount};
                actions.push_back(action);
                continue;
            }

            if (direction == "row") {
                action_t action;
                action.type = action_type_t::Horizontal;
                size_t row = read_int_cut(line, 4);
                size_t amount = read_int_cut(line, 0);
                action.action.right =
                    (rotation_t){.axis = row, .amount = amount};
                actions.push_back(action);
                continue;
            }
        }
    }

    const constexpr size_t SCREEN_WIDTH = 50;
    const constexpr size_t SCREEN_HEIGHT = 6;
    std::array<std::array<bool, SCREEN_WIDTH>, SCREEN_HEIGHT> screen = {0};

    for (auto& act : actions) {
        switch (act.type) {
            case action_type_t::Rectangle:
                light_rectangle(screen, act.action.rect.x, act.action.rect.y);
                break;
            case action_type_t::Horizontal:
                rotate_horizontally(screen, act.action.right.axis,
                                    act.action.right.amount);
                break;
            case action_type_t::Vertical:
                rotate_vertically(screen, act.action.down.axis,
                                  act.action.down.amount);
                break;
        }

        print_screen(screen);
        std::cout << '\n';
    }

    size_t pixel_count = 0;
    for (size_t i = 0; i < SCREEN_HEIGHT; i++) {
        for (size_t j = 0; j < SCREEN_WIDTH; j++) {
            pixel_count += (size_t)screen[i][j];
        }
    }

    std::cout << pixel_count << '\n';
}
