#include <iostream>
 
enum Day {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};
int main()
{
    Day today = Day::Thursday;
    std::cout << "Today: " << static_cast<int>(today) << std::endl;
}