#include <iostream>

int main () {
    struct Person {
        int age;
        char name[20];
    };

    Person p1 {14, "Maria"};
    Person p2 {10, "Georg"};

    if (p1.age > p2.age) {
    std::cout << p1.name << " is older, " << p1.age << std:: endl;
    } else {
    std::cout << p2.name << " is older, " << p2.age << std:: endl;
    }

    return 0;
}