#include <string_view>
#include <cassert>

int countOnes(std::string_view s)
{
    int count{};

    for (size_t i{}; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            count++;
        }
    }
    return count;
}

void runTests()
{
    assert(countOnes("0101010") == 3);
    assert(countOnes("00000") == 0);
    assert(countOnes("11111") == 5);
    assert(countOnes("abcd11") == 2);
    assert(countOnes("hello") == 0);
}

int main()
{
    runTests();
}