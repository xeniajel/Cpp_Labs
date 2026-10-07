#include <iostream>

int main () {
    int x = 5;
    int y = 3;
    x&= y;
    std::cout << x << y;
    x |=1;
    std::cout << x << y;
    x^=2;
    std::cout << x << y;
}