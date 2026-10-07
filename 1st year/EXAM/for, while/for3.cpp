#include <iostream>

int main () {
    for (int i=0; i<=15; i++) {
        if (i==8) break;
        std::cout << "Number until 7 is:" << i << std::endl;
    }
}