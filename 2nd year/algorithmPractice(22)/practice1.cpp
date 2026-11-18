#include <span>
#include <cassert>

void product(std::span<int> inputOutput, std::span<const int> coefficients)
{
    assert(inputOutput.size() == coefficients.size());
    for (size_t i{}; i < inputOutput.size(); i++)
    {
        inputOutput[i] = inputOutput[i] * coefficients[i];
    }
}

void product1(std::span<int> inputOutput, std::span<const int> coefficients)
{
    size_t i{};

    while (i < inputOutput.size())
    {
        inputOutput[i] = inputOutput[i] * coefficients[i];
        i++;
    }
}

void product2(std::span<int> inputOutput, std::span<const int> coefficients)
{
    size_t i{};

    while (true)
    {
        if (i == inputOutput.size())
        {
            break;
        }
        inputOutput[i] = inputOutput[i] * coefficients[i];
        i++;
    }
}
