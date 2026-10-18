#include <iostream>
#include <array>

struct Position{
    int x;
    int y;
};

struct MapDelivery{
    std::array<Position, 4> positions;
};

void Visit(MapDelivery map, Position start, int indexFirst, int indexSecond)
{
    int dx = map.positions[indexFirst].x - start.x;
    int dy = map.positions[indexFirst].y - start.y;

    std::cout << "First move: " << dx << ", " << dy << std::endl;

    start.x = map.positions[indexFirst].x;
    start.y = map.positions[indexFirst].y;

    int dx2 = map.positions[indexSecond].x - start.x;
    int dy2 = map.positions[indexSecond].y - start.y;

    std::cout << "Second move: " << dx2 << ", " << dy2 << std::endl;

    start.x = map.positions[indexSecond].x;
    start.y = map.positions[indexSecond].y;

    std::cout << "Final position: " << start.x << ", " << start.y << std::endl;
}

int main()
{
    MapDelivery map{
        {{{3, 4}, {6, 8}, {2, 5}, {9, 1}}}
    };

    Position start{1, 2};

    Visit(map, start, 0, 1);
}