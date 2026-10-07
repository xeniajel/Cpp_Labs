#include <iostream>
#define TEST 

int main () {
    #ifdef TEST
        std::cout << "Test mode";
    #else
        std::cout << "Normal mode";
    #endif

}