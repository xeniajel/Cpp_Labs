#include <iostream>

int main () {
    enum err {OK = 0, WARNING = 1, CRITICAL = 5};
    err r = CRITICAL;
    std::cout << r;
}