#include <iostream>

int main() {
    enum level {EASY, MEDIUM, HARD};
    level l = EASY;
    if (l = MEDIUM)
        std::cout << "Normal level";
    else
        std::cout << "Not normal level";
}