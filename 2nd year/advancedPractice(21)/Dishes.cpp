// Замочить посуду. 
// На кухне 2 сушилки по 3 тарелки. 
// Каждая тарелка бывает грязной или замоченной. 
// Замочите каждую грязную тарелку в сушилке 0.
#include <array>
#include <span>

enum State
{
    DIRTY,
    SOAKED,
};

struct Plate
{
    State plateState;
};

struct DryingRack
{
    std::array<Plate, 3> rack;
};

struct Kitchen
{
    std::array<DryingRack, 2> racks;
};

bool soak_dirty_plates(Kitchen& kitchen, size_t rackIndex)
{
    if(rackIndex >= kitchen.racks.size())
    {
        return false;
    }
    std::span<Plate> rack {kitchen.racks[rackIndex].rack};
    for(auto& dish : rack)
    {
        if(dish.plateState == DIRTY)
        {
            dish.plateState = SOAKED;
        }
    }
    return true;
}