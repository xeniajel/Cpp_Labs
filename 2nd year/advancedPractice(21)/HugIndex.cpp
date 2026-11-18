// Объятия в семье по индексам. 
// Те же 5 человек, но каждый хранит 
// индексы обнятых (std::array<int, 4>) вместо указателей
//  — теперь объятия имеют смысл только вместе с массивом семьи, на который указывают индексы.
//  Обнимите всех по разу.

#include <array>
#include <span>
#include <cassert>

struct Person
{
    std::array<int, 4> hugged{};
    int huggedCount{};
};

struct Family
{
    std::array<Person, 5> people{};
};

bool has_person_in_hugged(Person& first, int secondIndex)
{
    std::span<int> hugged = {
        first.hugged.data(),
        static_cast<size_t>(first.huggedCount)
    };

    for (auto personHugged : hugged)
    {
        if (personHugged == secondIndex)
        {
            return true;
        }
    }

    return false;
}

bool has_hugged(Person& person, int personIndex, Person& other, int otherIndex)
{
    return has_person_in_hugged(person, otherIndex)
        || has_person_in_hugged(other, personIndex);
}

bool hug(Person& person, int personIndex, Person& other, int otherIndex)
{
    if (has_hugged(person, personIndex, other, otherIndex))
    {
        return false;
    }

    person.hugged[person.huggedCount] = otherIndex;
    person.huggedCount++;

    other.hugged[other.huggedCount] = personIndex;
    other.huggedCount++;

    return true;
}

void hug_all(Family& family)
{
    for (size_t i{}; i < family.people.size(); i++)
    {
        for (size_t j{i + 1}; j < family.people.size(); j++)
        {
            hug(family.people[i], static_cast<int>(i),
                family.people[j], static_cast<int>(j));
        }
    }
}

int main()
{
    Family family{};

    hug_all(family);

    for (const auto& member : family.people)
    {
        assert(member.huggedCount == 4);
    }

    return 0;
}