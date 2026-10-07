#include <iostream>

int main () {
int arr[2]{};
int* p = arr;
*(p + 1) = 6;

std::cout << arr[1];
std::cout << std::endl;
}