#include <array>
int main()
{
    auto arr = std::array<std::array<int, 2>, 3>{
        std::array<int, 2>{1, 2},
        std::array<int, 2>{3, 4},
        std::array<int, 2>{5, 6},
    };
    std::array<int, 2> firstRow{arr[0]};
    std::array<int, 2> lastRow{arr[2]};
    arr[0][0] = 7;
    arr[2][1] = 8;
    arr[1] = {9, 10};
}