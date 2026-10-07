#include <iostream>

struct Car {
        int year;
        float price;
        char brand[20];
    };
int main () {
    Car c1 {2015, 12000.5, "Toyota"};

    std:: cout << "Brand: " << c1.brand << "\n";
    std:: cout << "Year: " << c1.year << "\n";
    std:: cout << "Price: " << c1.price << std::endl;
    
    return 0;
}