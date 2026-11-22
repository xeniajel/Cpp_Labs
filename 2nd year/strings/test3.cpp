#include <iostream>
#include <string_view>
#include <array>

void usage(std::string_view v)
{
    std::cout << v.size() << std::endl;
    std::cout << v << std::endl;
}

int main()
{
    {
        std::array<char, 3> s{ 'a', '\0', 'c' };
        usage({ s.data(), s.size() });
    }
    {
        auto s{ std::to_array("a\0c") };
        usage({ s.data() });
    }
    {
        char s[]{ "a\0c" };
        usage({ s });
    }
    {
        auto& s{ "a\0c" };
        usage({ s });
    }
    {
        const char* s{ "a\0c" };
        usage({ s });
    }
    {
        std::string_view s{ "a\0c", 3 };
        usage({ s }); // 3
    }
}