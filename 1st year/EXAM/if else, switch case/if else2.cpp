#include <iostream>

int main () {
    int x = -7;
    if (x==0)
        std::cout << "Zero";
    else if (x<0)
        std::cout <<"Negative";
    else
        std::cout << "Positive";
}