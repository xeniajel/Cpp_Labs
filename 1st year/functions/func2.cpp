#include <iostream>

int maxoftwo (int a, int b){
    if (a<b)
    {
        return b;
    }
    else {
    return a;
    }
};

int main () {
    int a;
    int b;
    std::cin >> a;
    std::cin >> b;
    std::cout << maxoftwo (a,b) << std::endl; 
}