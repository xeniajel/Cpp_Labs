#include <span>

int countGreaterThanFive(std::span<const int> arr)
{
    int count{};
    for (int i{}; i < arr.size(); i++)
    {
        if (arr[i] > 5)
        {
            count++;
        }
    }
}

int countGreaterThanFive1(std::span<const int> arr)
{
    int count{};
    size_t i{};

    while (i < arr.size())
    {
        if (arr[i] > 5)
        {
            count++;
        }
        i++;
    }
}

int countGreaterThanFive2(std::span<const int> arr)
{
    int count;
    size_t i{};

    while (true)
    {
        if (i == arr.size())
        {
            break;
        }

        if (arr[i] > 5)
        {
            count++;
        }

        i++;
    }
}