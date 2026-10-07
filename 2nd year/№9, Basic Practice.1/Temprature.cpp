#include <iostream>

struct Temprature
{
    int first;
    int second;
};

double AverageTemprature(Temprature temp)
{
    return (temp.first + temp.second) / 2.0;
}

int main()
{
    Temprature temp{
        .first = 23,
        .second = 18,
    };

    double averageTemprature = AverageTemprature(temp);
    std::cout << "The average temp is " << averageTemprature << std::endl;
}