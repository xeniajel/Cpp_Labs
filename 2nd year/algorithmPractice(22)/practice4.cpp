// Поиск двух наибольших значений в массиве
#include <span>
#include <cassert>
#include <array>

std::array<int, 2> findTwoMax(std::span<const int> arr)
{
    assert(arr.size() >= 2);
    int max1;
    int max2;

    if (arr[0] > arr[1])
    {
        max1 = arr[0];
        max2 = arr[1];
    }
    else
    {
        max1 = arr[1];
        max2 = arr[0];
    }

    for (size_t i = 2; i < arr.size(); i++)
    {
        if (arr[i] > max1)
        {
            max2 = max1;
            max1 = arr[i];
        }
        if (arr[i] < max1 && arr[i] > max2)
        {
            max2 = arr[i];
        }
    }
    std::array<int, 2> twoMax{max1, max2};
    return twoMax;
}

std::array<int, 2> findTwoMax1(std::span<const int> arr)
{
    assert(arr.size() >= 2);
    int max1;
    int max2;

    if (arr[0] > arr[1])
    {
        max1 = arr[0];
        max2 = arr[1];
    }
    else
    {
        max1 = arr[1];
        max2 = arr[0];
    }

    size_t i = 2;

    while (i < arr.size())
    {
        if (arr[i] > max1)
        {
            max2 = max1;
            max1 = arr[i];
        }
        if (arr[i] < max1 && arr[i] > max2)
        {
            max2 = arr[i];
        }
        i++;
    }
    std::array<int, 2> twoMax{max1, max2};
    return twoMax;
}

std::array<int, 2> findTwoMax2(std::span<const int> arr)
{
    assert(arr.size() >= 2);
    int max1;
    int max2;

    if (arr[0] > arr[1])
    {
        max1 = arr[0];
        max2 = arr[1];
    }
    else
    {
        max1 = arr[1];
        max2 = arr[0];
    }

    size_t i = 2;

    while (true)
    {
        if(i==arr.size())
        {
            break;
        }
        if (arr[i] > max1)
        {
            max2 = max1;
            max1 = arr[i];
        }
        if (arr[i] < max1 && arr[i] > max2)
        {
            max2 = arr[i];
        }
        i++;
    }
    std::array<int, 2> twoMax{max1, max2};
    return twoMax;
}