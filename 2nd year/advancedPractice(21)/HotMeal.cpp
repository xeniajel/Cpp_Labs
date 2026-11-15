#include <array>
#include <optional>
#include <span>

enum Warmth
{
    COLD,
    HOT
};

struct Pizza
{
    Warmth warmth;
};

struct Fridge
{
    std::array<std::optional<Pizza>, 3> shelves;
};

struct Freezer
{
    std::array<std::optional<Pizza>, 3> shelves;
};

struct Microwave
{
    std::optional<Pizza> pizza;
};

struct Kitchen
{
    Fridge fridge;
    Freezer freezer;
    Microwave microwave;
};

bool move_to_microwave(Fridge& fridge, Microwave& microwave, size_t shelfIndex)
{
    if (shelfIndex >= fridge.shelves.size())
    {
        return false;
    }

    std::span<std::optional<Pizza>> shelves{fridge.shelves};

    if (!shelves[shelfIndex].has_value())
    {
        return false;
    }

    if (microwave.pizza.has_value())
    {
        return false;
    }

    microwave.pizza = shelves[shelfIndex];
    shelves[shelfIndex].reset();

    return true;
}

bool heat_pizza(Microwave& microwave)
{
    if (!microwave.pizza.has_value())
    {
        return false;
    }

    microwave.pizza->warmth = HOT;

    return true;
}

bool move_to_freezer(Microwave& microwave, Freezer& freezer, size_t shelfIndex)
{
    if (shelfIndex >= freezer.shelves.size())
    {
        return false;
    }

    std::span<std::optional<Pizza>> shelves{freezer.shelves};

    if (!microwave.pizza.has_value())
    {
        return false;
    }

    if (shelves[shelfIndex].has_value())
    {
        return false;
    }

    if (microwave.pizza->warmth != HOT)
    {
        return false;
    }

    shelves[shelfIndex] = microwave.pizza;
    microwave.pizza.reset();

    return true;
}

int main()
{
    Kitchen kitchen{};

    kitchen.fridge.shelves[0] = Pizza{COLD};

    bool movedToMicrowave = move_to_microwave(
        kitchen.fridge, kitchen.microwave, 0);

    if (!movedToMicrowave)
    {
        return 1;
    }

    bool heated = heat_pizza(kitchen.microwave);

    if (!heated)
    {
        return 1;
    }

    bool movedToFreezer = move_to_freezer(
        kitchen.microwave, kitchen.freezer, 1);

    if (!movedToFreezer)
    {
        return 1;
    }

    return 0;
}