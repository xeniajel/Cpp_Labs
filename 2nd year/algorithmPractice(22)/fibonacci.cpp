#include <iostream>

void generateFibonacciFor(int n)
{
    int firstValue{}, secondValue{1}, nextValue{}, count{};

    for (; count < n;)
    {
        std::cout << firstValue << " ";
        count++;

        nextValue = firstValue + secondValue;
        firstValue = secondValue;
        secondValue = nextValue;
    }
}

void generateFibonacciWhile(int n)
{
    int firstValue{}, secondValue{1}, nextValue{}, count{};

    while (count < n)
    {
        std::cout << firstValue << " ";
        count++;

        nextValue = firstValue + secondValue;
        firstValue = secondValue;
        secondValue = nextValue;
    }
}

void generateFibonacciWhileBreak(int n)
{
    int firstValue{}, secondValue{1}, nextValue{}, count{};

    while (true)
    {
        if (count == n)
        {
            break;
        }
        std::cout << firstValue << " ";
        count++;

        nextValue = firstValue + secondValue;
        firstValue = secondValue;
        secondValue = nextValue;
    }
}

int main()
{
    generateFibonacciFor(19);
}