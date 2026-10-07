#include <iostream>

int main (){
    int a = 10;
    int* p = &a;
    std::cout << *p << std::endl;
    *p = 20;
    std::cout << *p << std::endl;
}