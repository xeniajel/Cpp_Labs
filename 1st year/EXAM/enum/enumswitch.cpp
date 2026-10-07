#include <iostream>

int main () {
    enum direction {LEFT, RIGHT, UP, DOWN};
    direction r = UP;
    switch (r) {
    case LEFT: std::cout << "Go left";
        break;
    case RIGHT: std::cout << "Go right";
        break;
    case UP: std::cout << "Go up";
        break;
    case DOWN: std::cout << "Go down";
        break;
    default: std::cout << "Direction is unknown. Error";
    }
}