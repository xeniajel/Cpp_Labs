#include <iostream>

int main () {
    int score = 87;
    if (score<=100 && score>=90)
        std::cout << "5";
    else if (score<=89 && score>=75)
        std::cout << "4";
    else if (score<=74 && score>=60)
        std::cout << "3";
    else
        std::cout << "2";  
}