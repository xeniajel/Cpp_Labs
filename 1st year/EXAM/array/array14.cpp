#include <iostream>

int main () {
    int arr[6] = {5,3,4,999,9,88};
    int min = arr[0];
    for (int i = 0; i<6; i++) {
        if (arr[i]<min){
            min = arr[i];
        };
    }
    std::cout << min;
}