//Столовая. Столовая хранит 3 супа и 3 хлеба. 
//Подайте суп 1 с хлебом 1. При подаче оба забираются.
#include <array>
#include <optional>
#include <span>

struct Soup{};
struct Bread{};

struct Canteen{
    std::array<std::optional<Soup>, 3> soups;
    std::array<std::optional<Bread>, 3> breads;
};

bool serve_meal(Canteen& canteen, size_t soupIndex, size_t breadIndex)
{
    std::span<std::optional<Soup>> soups {canteen.soups};
    std::span<std::optional<Bread>> breads {canteen.breads};

    if(soupIndex >= soups.size())
    {
        return false;
    }
    if(breadIndex >= breads.size())
    {
        return false;
    }
    if(!soups[soupIndex].has_value() || !breads[breadIndex].has_value())
    {
        return false;
    }

    soups[soupIndex].reset();
    breads[breadIndex].reset();
    return true;
}

int main()
{
    Canteen canteen{};

    canteen.soups[0] = Soup{};
    canteen.breads[0] = Bread{};

    bool result = serve_meal(canteen, 0, 0);

    return 0;
}