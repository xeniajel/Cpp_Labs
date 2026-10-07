#include  <iostream>

int main () {
    int n;
    std::cout << "Enter size";
    std::cin >> n;
    int max = 0;

    int* arr = new int[n];
    for (int i = 0;i<n;i++)
        if (max<arr[i])
            max = arr[i];
    std::cout << max << std::endl;

    delete[]arr;
}