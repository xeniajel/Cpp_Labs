#include <iostream>

int main () {
    int choice = 3;
    switch (choice) {
    case 1: std::cout << "Rock";
        break;
    case 2: std::cout << "Paper";
        break;
    case 3: std::cout << "Scissors";
        break;
    default:
        std::cout << "Invalid choice";
    }
}