// Замачивание белья. Корзина вмещает 3 вещи.
// В прачечной 2 корзины. У каждой вещи есть метка и состояние: грязная, замоченная или чистая.
// Достаньте каждую чистую рубашку из корзины 0, затем замочите каждую грязную рубашку в корзине 0.
// Посчитайте, сколько достали и сколько замочили.
#include <string_view>
#include <array>
#include <optional>

enum ClothState
{
    DIRTY,
    WET,
    CLEAN,
};

struct Cloth
{
    std::string_view label;
    ClothState state;
};

struct Basket
{
    std::array<std::optional<Cloth>, 3> clothes;
};

struct Laundry
{
    std::array<Basket, 2> baskets;
};

int take_clean_shirts(Basket &basket)
{
    int taken{0};
    for (auto &slot : basket.clothes)
    {
        if (!slot.has_value())
        {
            continue;
        }
        if (slot->state != ClothState::CLEAN)
        {
            continue;
        }
        slot.reset();
        taken++;
    }
    return taken;
}

int soak_basket(Basket &basket)
{
    int soaked{0};
    for (auto &slot : basket.clothes)
    {
        if (!slot.has_value())
        {
            continue;
        }
        if (slot->state != ClothState::DIRTY)
        {
            continue;
        }
        slot->state = ClothState::WET;
        soaked++;
    }
    return soaked;
}

int main()
{
    Laundry laundry{};
    laundry.baskets[0].clothes[0] = Cloth{
        .label = "shirt",
        .state = ClothState::DIRTY,
    };
    int taken{take_clean_shirts(laundry.baskets[0])};
    int n{soak_basket(laundry.baskets[0])};
}