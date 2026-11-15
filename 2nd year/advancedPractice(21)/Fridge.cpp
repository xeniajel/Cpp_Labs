#include <string_view>
#include <optional>
#include <array>

struct Product
{
    std::string_view name;
};

struct Fridge
{
    std::array<std::optional<Product>, 3> slots; // пицца на 1 полке холодильника
};

struct Freezer
{
    std::array<std::optional<Product>, 2> slots;
};

bool change_product(Fridge &fridge, size_t indexFrom, Freezer &freezer, size_t indexTo)
{
    if (indexFrom > fridge.slots.size())
    {
        return false;
    }
    if (indexTo > freezer.slots.size())
    {
        return false;
    }
    if (fridge.slots[indexFrom])
    {
        return false;
    }
    if (freezer.slots[indexTo])
    {
        return false;
    }
    freezer.slots[indexTo] = fridge.slots[indexFrom];
    fridge.slots[indexFrom].reset();
    return true;
}
int main()
{
    Fridge fridge{};
    fridge.slots[1] = Product{.name = "pizza"};
    Freezer freezer{};
    bool moved{ change_product(fridge, 1, freezer, 0) };
}