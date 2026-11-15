// Отряд героев. Отряд вмещает 3 героев.
// У каждого героя есть здоровье и щит. Полечите героя 1 на 20 единиц здоровья.
// Посчитайте, скольким героям все еще нужно лечение.

#include <iostream>
#include <optional>
#include <array>

struct Hero
{
    int health;
    int shield;
};

struct Squad
{
    std::array<std::optional<Hero>, 3> heroes;
};

bool heal_hero(Squad& squad, size_t index)
{
    if (index >= squad.heroes.size())
    {
        return false;
    }
    if (!squad.heroes[index].has_value())
    {
        return false;
    }
    squad.heroes[index]->health += 20;
    return true;
}

int count_heroes_to_heal(Squad& squad)
{
    int heroes_toHeal{};
    for(const auto& hero : squad.heroes)
    {
        if(!hero.has_value())
        {
            continue;
        }
        if(hero->health < 50)
        {
            heroes_toHeal++;
        }
    }
    return heroes_toHeal;
}

int main(){
    Squad squad{{{
        {std::nullopt},
        Hero{80, 10},
        Hero{49, 40}
    }}};

    std::cout << "Hero 1 health before healing: " << squad.heroes[1]->health << std::endl;

    std::cout << heal_hero(squad, 0) << std::endl;

    heal_hero(squad, 1);
    std::cout << "Hero 1 health after healing: " << squad.heroes[1]->health << std::endl;

    int needtoHeal = count_heroes_to_heal(squad);
    std::cout << needtoHeal;
}
