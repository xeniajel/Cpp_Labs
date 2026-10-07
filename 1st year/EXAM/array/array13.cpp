#include <iostream>

int main () {
    int arr[6] = {4, 6, 3, 5, 67, 90};
    int max = 0;

    for (int i = 0; i<6;i++) {
    if (arr[i]>max) {
        max=arr[i];
        }
    }
    std::cout << "The maximum is " << max << std::endl; 
}