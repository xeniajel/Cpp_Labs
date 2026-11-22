#include <string_view>
#include <cassert>

std::string_view secondWord(std::string_view s)
{
    for (size_t i{}; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            for (size_t j{i + 1}; j < s.size(); j++)
            {
                if (s[j] == ' ')
                {
                    return s.substr(i + 1, j - (i + 1));
                }
            }
            return s.substr(i + 1);
        }
    }
    return std::string_view{};
}

void tests()
{
    assert(secondWord("Hello world") == "world");
    assert(secondWord("Hello my dear") == "my");
    assert(secondWord("Hello") == "");
    assert(secondWord("") == "");
    assert(secondWord(" ") == "");
    assert(secondWord(" a ") == "a");
    assert(secondWord("a  ") == "");
    assert(secondWord("a  b") == "");
    assert(secondWord("hello     world    dear") == "");
    assert(secondWord("011010dkdkdl ldld l l ") == "ldld");
}

int main()
{
    tests();
}