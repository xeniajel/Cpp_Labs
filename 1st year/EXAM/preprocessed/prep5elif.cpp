#include <iostream>
#define VERSION 2

int main () {
    #if VERSION == 1
        std::cout << "Version 1";
    #elif VERSION == 2
        std::cout << "Version 2";
    #elif VERSION == 3
        std::cout << "Version 3";
    #else
        std::cout << "Unknown";
    #endif
}