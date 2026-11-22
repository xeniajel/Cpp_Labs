#include <array>
#include <iostream>

bool divideExactly(int dividend, int divisor, int& quotient)
{
    if (dividend < 0 || divisor <= 0)
    {
        return false;
    }
    if (dividend % divisor != 0)
    {
        return false;
    }
    quotient = dividend / divisor;
    return true;
}

int main()
{
    {
        int quotient = 99;
        bool success = divideExactly(8, 2, quotient);
        std::cout << success << std::endl;
        std::cout << quotient << std::endl;
    }
    {
        int quotient{};
        bool success = divideExactly(9, 2, quotient);
        std::cout << success << std::endl;
        std::cout << quotient << std::endl;
    }
}