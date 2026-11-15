// Тюнинг машины. Гараж вмещает 4 машины.
// У каждой машины есть модель, мощность и цена.
// Тюнингуйте машину 2: увеличьте мощность на 10,
// а цену — на 1000 за каждую добавленную единицу мощности.
#include <string_view>
#include <optional>
#include <array>
#include <iostream>

struct Car
{
    std::string_view model;
    int power;
    double price;
};

struct Garage
{
    std::array<std::optional<Car>, 4> cars;
};

bool tuningCar(Garage &garage, size_t index)
{
    if (index >= garage.cars.size())
    {
        return false;
    }
    if (!garage.cars[index].has_value())
    {
        return false;
    }
    int power = 10;
    garage.cars[index]->power += power;
    garage.cars[index]->price += 1000 * power;
    return true;
}

int main()
{
    Garage garage{};

    garage.cars[2] = Car{"Toyota", 120, 15000.0};

    std::cout << "Before: "
              << garage.cars[2]->power << " HP, "
              << garage.cars[2]->price << '\n';

    bool result = tuningCar(garage, 2);

    std::cout << "Success: " << std::boolalpha << result << '\n';

    std::cout << "After: "
              << garage.cars[2]->power << " HP, "
              << garage.cars[2]->price << '\n';
}