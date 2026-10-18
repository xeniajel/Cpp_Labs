#include <iostream>
#include <array>

struct Tariffs
{
    std::array <int, 3> categories;
};

int calculateCost(Tariffs tariff, int category, int tickets, int givenMoney)
{
    int totalCost = tickets * tariff.categories[category];
    return givenMoney - totalCost;
}

int main(){
    Tariffs tariff {10, 15, 20};
    int given_money = 100;

    int change = calculateCost(tariff, 2, 3, given_money);

    std::cout << "Change is " << change << std::endl;
}