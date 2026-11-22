#include<array>
#include<iostream>

int main()
{
    auto s{std::to_array("abc")}; // to_array делает массивом то что в скобках
    std::cout << s.size() << std::endl;

    auto d{std::to_array("a\0bc")}; // функция учитывает весь массив, будет 5 элементов
    std::cout << d.size() << std::endl;
}