#include <iostream>
#include <array>

int main()
{
    std::array<int, 2> arr{ 1, 2 };
    std::array<int, 2>* p{ &arr };
    p->at(0) = 3;
    (*p)[1] = 4;
    std::cout << arr[0] << std::endl;
    std::cout << arr[1] << std::endl;
}