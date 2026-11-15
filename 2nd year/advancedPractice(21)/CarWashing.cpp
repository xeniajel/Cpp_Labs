//Мойка машин. Мойка вмещает 3 машины. 
//Каждая машина бывает чистой или грязной. 
//Помойте каждую грязную машину. Посчитайте, сколько было помыто.
#include <iostream>
#include <array>
#include <optional>

enum class CarState
{
    CLEAN,
    DIRTY,
};

struct Car
{
    CarState state;
};

struct CarWash
{
    std::array<std::optional<Car>, 3> cars;
};

int washCars(CarWash& wash)
{
    int washedCount = 0;

    for (auto& car : wash.cars)
    {
        if (car.has_value() && car->state == CarState::DIRTY)
        {
            car->state = CarState::CLEAN;
            washedCount++;
        }
    }

    return washedCount;
}

int main()
{
    CarWash wash{{
        Car{CarState::DIRTY},
        Car{CarState::CLEAN},
        Car{CarState::DIRTY}
    }};

    std::cout << "Washed cars: " << washCars(wash) << '\n';
}