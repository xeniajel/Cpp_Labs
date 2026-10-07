#include <iostream>

int main() {
    int h = 3;
    switch (h) {
    case 0: case 1: case 2: case 3: case 4: case 5:
        std::cout << "Night";
        break;
    case 6: case 7: case 8: case 9: case 10: case 11:
        std::cout << "Morning";
        break;
    case 12: case 13: case 14: case 15: case 16: case 17:
        std::cout << "Day";
        break;
    case 18: case 19: case 20: case 21: case 22: case 23:
        std::cout << "Evening";
        break;
    }
}