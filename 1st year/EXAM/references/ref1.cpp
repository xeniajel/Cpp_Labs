#include <iostream>

int main () {
    int a = 15;
    int& r = a;
    r *= 2;
    std::cout << r;
}