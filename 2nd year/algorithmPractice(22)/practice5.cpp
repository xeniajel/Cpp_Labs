// Генерирование первых n простых чисел;
#include <iostream>

bool isPrime(int num)
{
    if (num < 2)
    {
        return false;
    }
    for (size_t i = 2; i < num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

void generatePrimes(int n)
{
    int num = 2;
    int count = 0;
    for (; count < n; num++)
    {
        if (isPrime(num))
        {
            count++;
            std::cout << num << ", ";
        }
    }
}

void generatePrimes1(int n)
{
    int num = 2;
    int count = 0;

    while (count < n)
    {
        if (isPrime(num))
        {
            count++;
            std::cout << num << ", ";
        }
        num++;
    }
}

void generatePrimes2(int n)
{
    int num = 2;
    int count = 0;

    while (true)
    {
        if(count == n)
        {
            break;
        }
        if (isPrime(num))
        {
            count++;
            std::cout << num << ", ";
        }
        num++;
    }
}

int main()
{
    generatePrimes(100);
}