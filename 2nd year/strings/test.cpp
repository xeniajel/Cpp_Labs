#include <iostream>
#include <array>

int main() 
{
    // \0 pit fall
    char arr[]{"1\023"}; // здесь \023 будет как один символ из восьмеричной системы
    // В C++ после \ три цифры от 0 до 7 обозначают символ по его восьмеричному коду.
    // 023 с таблице ACHII это DCV (Device Control Three (XOFF))
    std::cout << sizeof(arr) << std::endl;
    std::cout << arr << std::endl;
}