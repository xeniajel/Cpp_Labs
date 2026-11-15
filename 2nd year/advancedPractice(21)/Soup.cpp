// Разогрев супа. Микроволновка либо вмещает одно блюдо, либо пуста.
//  У каждого блюда есть название и состояние нагрева: холодное или горячее.
// Положите холодный суп внутрь, разогрейте до горячего состояния, затем достаньте.
#include <string_view>
#include <optional>

enum class Warmth
{
    COLD,
    HOT,
};

struct Product
{
    std::string_view name;
    Warmth warmth;
};

struct Microwave
{
    std::optional<Product> tray;
};

bool put_meal(Microwave &microwave, Product meal)
{
    if (microwave.tray.has_value())
    {
        return false;
    }
    microwave.tray = meal;
    return true;
}

bool heat_meal(Microwave &microwave)
{
    if (!microwave.tray.has_value())
    {
        return false;
    }
    microwave.tray->warmth = Warmth::HOT;
    return true;
}

std::optional<Product> take_meal(Microwave &m)
{
    if (!m.tray.has_value())
    {
        return std::nullopt;
    }
    std::optional<Product> result{m.tray};
    m.tray.reset();
    return result;
}
int main()
{
    Microwave mw{};
    put_meal(mw, Product{.name = "soup", .warmth = Warmth::COLD});
    heat_meal(mw);
    std::optional<Product> lunch{take_meal(mw)};
}
