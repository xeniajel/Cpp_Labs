// Рейлинг для чашек. Рейлинг рассчитан на 4 чашки.
// Некоторые крючки пусты.
// Повесьте новую чашку на первый пустой крючок и снимите чашку с крючка 1.
// При перемещении владение передаётся: скопируйте ее, затем очистите старое место.
#include <iostream>
#include <array>
#include <optional>

struct Cup
{
};

struct Railing
{
    std::array<std::optional<Cup>, 4> hooks;
};

bool put_cup(Railing &railing)
{
    for (int i = 0; i < railing.hooks.size(); i++)
    {
        if (!railing.hooks[i].has_value())
        {
            railing.hooks[i] = Cup{};
            return true;
        }
    }
    return false;
}

std::optional<Cup> take_cup(Railing &railing, size_t index)
{
    if(index >= railing.hooks.size())
    {
        return std::nullopt;
    }
    if (!railing.hooks[index].has_value())
    {
        return std::nullopt;
    }

    std::optional<Cup> takenCup = railing.hooks[index];
    railing.hooks[index].reset();

    return takenCup;
}

int main()
{
    Railing railing{};

    railing.hooks[0] = Cup{};
    railing.hooks[1] = Cup{};

    bool putResult = put_cup(railing);
    std::optional<Cup> takeResult = take_cup(railing, 1);

    for (int i = 0; i < railing.hooks.size(); i++)
    {
        std::cout << "Hook " << i << ": "
                  << railing.hooks[i].has_value() << '\n';
    }

    return 0;
}