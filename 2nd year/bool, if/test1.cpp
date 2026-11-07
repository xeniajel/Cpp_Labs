#include <iostream>

void func(bool b, int* a)
{
    std::cout << b << std::endl;
    *a = 2;
    std::cout << b << std::endl;
}

int main()
{
    int a { 1 };
    func(a == 1, &a);
}