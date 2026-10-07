#include <iostream>

struct Books {
    int pages;
    int year;
};

int main() {
    Books b1 {412, 1980};

    std::cout << "The number of pages is: " << b1.pages << std::endl;
    std::cout << "The year is: " << b1.year << std::endl;
    Books* ptr = &b1;
    ptr->pages = 300;
    (*ptr).year = 1967;

    std::cout << "The number of pages is: " << b1.pages << std::endl;
    std::cout << "The year is: " << b1.year << std::endl;

}