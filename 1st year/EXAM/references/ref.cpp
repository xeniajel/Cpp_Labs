#include <iostream>

int main() {
    int a = 10;
    int& ref = a;
    ref = 20;
    std::cout << a;
}