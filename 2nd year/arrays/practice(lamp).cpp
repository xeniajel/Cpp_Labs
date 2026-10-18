#include <iostream>
#include <array>

struct Lamp
{
    int brightness;
};

struct Panel
{
    std::array<Lamp*, 3> lamps;
};

int main()
{
    Lamp lamp1{30};
    Lamp lamp2{50};
    Lamp lamp3{70};

    Panel panel1{{&lamp1, &lamp2, &lamp3}};
    Panel panel2{{&lamp3, &lamp1, &lamp2}};

    panel1.lamps[2]->brightness = 90;

    std::cout << panel2.lamps[0]->brightness << std::endl;
}