#include <iostream>

int main () {
    struct Student {
    char name[20];
    double grade1;
    double grade2;
    double grade3;
    };
    Student n1 {"Anna", 8.0, 6.50, 9.0};
    double average = (n1.grade1 + n1.grade2 + n1.grade3) / 3.0;
    std::cout << n1.name << "'s average grade is " << average << std::endl;
}