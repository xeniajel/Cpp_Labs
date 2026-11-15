// Аптечка. Шкафчик вмещает 4 коробки. 
// Каждая коробка бывает свежей или просроченной. 
// Верните признак, можно ли использовать коробку 1. 
// Выбросите коробку 1, если она просрочена.
#include <array>
#include <optional>
#include <span>

enum BoxState
{
    FRESH,
    EXPIRED,
};

struct Box
{
    BoxState state;
};

struct Locker
{
   std::array<std::optional<Box>, 4> boxes;
};

bool remove_box(Locker& locker, size_t index)
{
    if(index >= locker.boxes.size())
    {
        return false;
    }
    std::span<std::optional<Box>> boxes{locker.boxes};

    if(!boxes[index].has_value())
    {
        return false;
    }

    switch (boxes[index]->state)
    {
        case FRESH:
        {
            return true;
        }
        case EXPIRED:
        {
            boxes[index].reset();
        }
    }
    return false;
}

int main()
{
    Locker locker{};

    locker.boxes[0] = Box{FRESH};
    locker.boxes[1] = Box{EXPIRED};
    locker.boxes[2] = Box{FRESH};

    bool result = remove_box(locker, 1);
}