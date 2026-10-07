#include <iostream> 
#include <cmath>
int square (int a)
{
    return a*a;
};

int main () {
    int c;
    std::cin >> c;
    std::cout << square (c) << std::endl;
}