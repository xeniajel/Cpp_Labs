#include <iostream>

struct Wagon
{
    int cargoWeight;
    Wagon* next;
};

void AddCargo(Wagon* first, int weight)
{
    first->next->cargoWeight += weight;

    std::cout << first->next->cargoWeight << std::endl;
}

int main()
{
    Wagon second{200, nullptr};
    Wagon first{100, &second};

    AddCargo(&first, 50);
}