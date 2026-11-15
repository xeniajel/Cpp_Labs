// Парковка. На парковке 2 этажа по 4 места.
// Каждое место либо хранит машину, либо пусто.
// Поставьте новую машину на первое пустое место.
// Пройдите по местам с помощью арифметики указателей.
#include <array>
#include <optional>
#include <iostream>

struct Car
{
};

struct Floor
{
    std::array<std::optional<Car>, 4> floor;
};

struct Parking
{
    std::array<Floor, 2> parkingFloors;
};

bool fun1(Parking &parking)
{
    Floor *pointerFloor = parking.parkingFloors.data();

    for (int i = 0; i < parking.parkingFloors.size(); i++)
    {
        std::optional<Car> *pointerCar = pointerFloor->floor.data();

        for (int j = 0; j < pointerFloor->floor.size(); j++)
        {
            if (!pointerCar->has_value())
            {
                *pointerCar = Car{};
                return true;
            }
            pointerCar += 1;
        }
        pointerFloor++;
    }
    return false;
}
int main()
{
    Parking parking{};

    parking.parkingFloors[0].floor[0] = Car{};
    parking.parkingFloors[0].floor[1] = Car{};

    bool result = fun1(parking);

    std::cout << std::boolalpha << "Parked: " << result << '\n';

    for (const auto &floor : parking.parkingFloors)
    {
        for (const auto &place : floor.floor)
        {
            std::cout << (place.has_value() ? "[X] " : "[ ] ");
        }
        std::cout << '\n';
    }
}