#include <iostream>
#include <array>

void func(int arr[])
{
   std::cout << arr[0] << std::endl;
   std::cout << arr[1] << std::endl;
   std::cout << arr[2] << std::endl;
}

int main()
{
   std::array<int, 2> arr{1, 2};
   func(arr.data());
}