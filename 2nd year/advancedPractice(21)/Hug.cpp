#include <array>
#include <span>
#include <cassert>

struct Person
{
    std::array<Person *, 4> hugged{};
    int huggedCount{};
};

struct Family
{
    std::array<Person, 5> people;
};

bool has_person_in_hugged(Person &first, Person &second)
{
    std::span<Person *> hugged = {first.hugged.data(), static_cast<size_t>(first.huggedCount)};

    for (auto personHugged : hugged)
    {
        if (personHugged == &second)
        {
            return true;
        }
    }
    return false;
}

bool has_hugged(Person &person, Person &other)
{
    return has_person_in_hugged(person, other) || has_person_in_hugged(other, person);
}

bool hug(Person &person, Person &other)
{
    if (has_hugged(person, other))
    {
        return false;
    }
    else
    {
        person.hugged[person.huggedCount] = &other;
        person.huggedCount++;

        other.hugged[other.huggedCount] = &person;
        other.huggedCount++;
    }
    return true;
}

void hug_all(Family &family)
{
    for (size_t i{}; i < family.people.size(); i++)
    {
        for (size_t j{i + 1}; j < family.people.size(); j++)
        {
            hug(family.people[i], family.people[j]);
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
}