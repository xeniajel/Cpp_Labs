#include <iostream>

void swap(int* a, int* b)
{
    int temp{ *a };
    *a = *b;
    *b = temp;
}

int main()
{
    int x{ 10 };
    int y{ 20 };

    swap(&x, &y);

    std::cout << "x = " << x << ", y = " << y << std::endl; // x = 20, y = 10
}