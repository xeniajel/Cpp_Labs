#include <iostream>

int main () {
    int i = 10;
    do {
        std::cout << "The number: " << i << std::endl;
        i -=10;
    } while (i>15);
}