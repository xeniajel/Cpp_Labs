#include <iostream>

int main () {
    for (int i = 0; i<21; i++) {
        if (i % 2 == 0) continue;
        std::cout << "Odd number: " << i << std::endl;
    }

}
// only odd numbers with operator 'continue'