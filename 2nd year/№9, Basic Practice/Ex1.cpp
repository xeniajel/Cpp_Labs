#include <iostream>

struct Battery
{
    int chargePercent;
};

void charge(Battery* battery, int minutes)
{
    battery->chargePercent = std::min(100, battery->chargePercent + minutes);
}

int main()
{
    Battery battery{ .chargePercent = 10 };
    charge(&battery, 10);
    std::cout << battery.chargePercent << std::endl;
}