#include<span>
#include <cassert>

int findMax(std::span<const int> arr)
{
    assert(arr.size()!=0);
    int max = arr[0];
    for(size_t i = 1; i < arr.size(); i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

int findMax1(std::span<const int> arr)
{
    assert(arr.size()!=0);
    int max = arr[0];
    size_t i = 1;

    while(i<arr.size())
    {
        if(max < arr[i])
        {
            max = arr[i];
        }
        i++;
    }
    return max;
}

int findMax1(std::span<const int> arr)
{
    assert(arr.size()!=0);
    int max = arr[0];
    size_t i = 1;

    while(true)
    {
        if(i==arr.size())
        {
            break;
        }
        if(max < arr[i])
        {
            max = arr[i];
        }
        i++;
    }
    return max;
}