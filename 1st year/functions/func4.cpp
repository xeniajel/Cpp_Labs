#include <iostream>

int max (int a, int b) {
    return a+b;
};
int main () {
    int a;
    int b;
    std::cin >> a;
    std::cin >> b;
    std::cout << max(a,b) << std::endl;
}