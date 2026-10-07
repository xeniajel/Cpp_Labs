#include <iostream>

int main () {
    int x = 10;
    int y = 9;
    if (x<y)
        std::cout << "The biggest is " << y;
    else 
        std::cout << "The biggest is " << x;
}