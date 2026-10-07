#include <iostream>

int main () {
    int x = 5;
    int y = 4;
    char op = '+';
    switch (op) {
    case '-': std::cout << x-y;
        break;
    case '*': std::cout << x*y;
        break;
    case '+': std::cout << x+y;
        break;
    case '/': std::cout << x/y;
    
    }
}