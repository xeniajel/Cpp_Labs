#include <array>
#include <optional>
#include <span>
#include<iostream>

struct Visitor;

struct RollerCoaster
{
    Visitor *currentVisitor{nullptr};
};

struct Visitor
{
    std::array<RollerCoaster *, 3> preferences;
    int numVisits;
    std::optional<RollerCoaster *> lastCoaster;
};

struct Park
{
    std::array<RollerCoaster, 3> coasters;
};

bool is_coaster_free(RollerCoaster &coaster)
{
    if (coaster.currentVisitor == nullptr)
    {
        return true;
    }
    return false;
}

bool was_visited_last(RollerCoaster &coaster, Visitor &visitor)
{
    if (!visitor.lastCoaster.has_value())
    {
        return false;
    }
    if (&coaster == (*visitor.lastCoaster))
    {
        return true;
    }
    return false;
}

RollerCoaster *find_available_coaster(Park &park, Visitor &visitor)
{
    for (size_t i{}; i < visitor.preferences.size(); i++)
    {
        if (was_visited_last(*visitor.preferences[i], visitor))
        {
            continue;
        }
        if (is_coaster_free(*visitor.preferences[i]))
        {
            return visitor.preferences[i];
        }
    }
    return nullptr;
}

void assign_visitors(Park &park, std::span<Visitor> visitors)
{
    for (auto &visitor : visitors)
    {
        if (visitor.numVisits == 4)
        {
            continue;
        }
        RollerCoaster *availableCoaster = find_available_coaster(park, visitor);
        if (availableCoaster != nullptr)
        {
            availableCoaster->currentVisitor = &visitor;
        }
    }
}

void tick_coaster(RollerCoaster &coaster)
{
    if (coaster.currentVisitor == nullptr)
    {
        return;
    }
    coaster.currentVisitor->numVisits++;

    coaster.currentVisitor->lastCoaster = &coaster;

    coaster.currentVisitor = nullptr;
}

void tick_all_coasters(Park &park)
{
    for (auto &coaster : park.coasters)
    {
        tick_coaster(coaster);
    }
}

bool all_visitors_done(std::span<Visitor> visitors)
{
    for (auto &visitor : visitors)
    {
        if (visitor.numVisits < 4)
        {
            return false;
        }
    }
    return true;
}

bool park_done(std::span<Visitor> visitors)
{
    return all_visitors_done(visitors);
}

int main()
{
    Park park{};

    Visitor alice{
        .preferences = {
            &park.coasters[0],
            &park.coasters[1],
            &park.coasters[2]},
        .numVisits = 0,
        .lastCoaster = nullptr

    };

    Visitor bob{
        .preferences = {
            &park.coasters[2],
            &park.coasters[0],
            &park.coasters[1]},
        .numVisits = 0,
        .lastCoaster = std::nullopt};

    std::array<Visitor, 2> visitors{alice, bob};

    while (!park_done(visitors))
    {
        assign_visitors(park, visitors);
        tick_all_coasters(park);
    }

    std::cout << "Alice visits: " << visitors[0].numVisits << '\n';
    std::cout << "Bob visits: " << visitors[1].numVisits << '\n';
}