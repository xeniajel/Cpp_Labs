#include <iostream>

struct A
{
    int* f[2];
};

int main()
{
    int var1;
    int var2;
    A a { .f = { &var1, &var2 } };
    *a.f[0] = 1;
    *a.f[1] = 2;
    int** b = a.f;
    int c = **b;

    std::cout << var1 << std::endl;
    std::cout << var2 << std::endl;

    std::cout << a.f[0] << std::endl;
    std::cout << a.f[1] << std::endl;

    std::cout << b << std::endl;
    std::cout << c << std::endl;
}