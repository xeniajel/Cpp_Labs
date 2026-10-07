#include <iostream>
#include <string>

int main () {
    struct Person {
        int age;
        char name[20];
    };
    Person p1 = {.age = 18, .name = "Joan"};

    std::cout << "Write the name" << std::endl;
    std::cin >> p1.name; 

    std::cout << "Write the age" << std::endl;
    std::cin >> p1.age;

    std::cout << "Name: " << p1.name << '\n';
    std::cout << "Age: " << p1.age << std::endl;

    return 0;
}
