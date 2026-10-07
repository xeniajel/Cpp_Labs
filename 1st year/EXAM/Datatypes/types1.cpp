#include <iostream>

int main () {
    int x = 5;
    int y = 4;
    std::cout <<"Sum is "<< x+y << std::endl;
    std::cout << "Difference is " << x-y << std::endl;

    char letter = 'X';
    std::cout << letter << std::endl;
    letter = 'K';
    std::cout << letter << std::endl;

    int age = 23;
    bool isAdult;
    if (age>=18)
        isAdult = 1;
    else
        isAdult = 0;
    std::cout << isAdult;
}
