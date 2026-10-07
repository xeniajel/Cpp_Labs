#include <iostream>

void swap (int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main () {
    int x = 5;
    int y = 8;
    swap(x,y);
    std::cout << x << " " << y;


}