#include <iostream>

int main () {
    int arr[5] = {1,2,4,5,6};
    int sum = 0;
    for(int i =0; i<5; i++) {
        sum += arr[i];
    }
    std::cout << sum;
}