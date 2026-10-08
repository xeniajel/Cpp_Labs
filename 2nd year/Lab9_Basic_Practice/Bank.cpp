#include <iostream>

struct PiggyBank
{
    int rubles;
    int kopecks;
};

void addMoney(PiggyBank* bank, int addRubles, int addKopecks)
{
    int totalKopecks{ bank->kopecks + addKopecks };
    bank->rubles += addRubles + totalKopecks / 100;
    bank->kopecks = totalKopecks % 100;
}

int main()
{
    PiggyBank bank{
        .rubles = 10,
        .kopecks = 80,
    };

    addMoney(&bank, 5, 50);

    std::cout << bank.rubles << " rub. " << bank.kopecks << " kop." << std::endl;
}