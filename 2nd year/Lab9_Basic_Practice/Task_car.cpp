#include <iostream>

struct Car
{
    int horsePower;
    int price;
};

void tune_car(Car* car, int addedHorsePower)
{
    car->horsePower += addedHorsePower;
    car->price += addedHorsePower * 1000;
}

int main()
{
    Car myCar{
        .horsePower = 150,
        .price = 20000,
    };

    tune_car(&myCar, 50);

    std::cout << "Horsepower: " << myCar.horsePower << std::endl; // 200
    std::cout << "Price: " << myCar.price << std::endl;           // 70000
}