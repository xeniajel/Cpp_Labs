// Двигатель машины. В гараже 4 машины. У каждой машины свой двигатель.
// У двигателя есть износ от 0 до 100.
// Проверьте двигатель через машину 1 и отремонтируйте двигатель машины 1 до износа 0.
#include <array>
#include <iostream>

struct Engine
{
    int wear;
};

struct Car
{
    Engine engine;
};

struct Garage
{
    std::array<Car, 4> cars;
};

bool Change_engine(Garage &garage, size_t index)
{
    if(index <= garage.cars.size())
    {
        return false;
    }
    garage.cars[index].engine.wear = 0;
    return true;
}

int main()
{
    Garage garage{};

    garage.cars[1].engine.wear = 75;

    std::cout << "Before repair: "
              << garage.cars[1].engine.wear << '\n';

    Change_engine(garage, 1);

    std::cout << "After repair: "
              << garage.cars[1].engine.wear << '\n';

    return 0;
}