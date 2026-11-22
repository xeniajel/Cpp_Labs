#include <iostream>

bool validateAge(int age, std::ostream& error)
{
    if (age < 0)
    {
        std::cerr << "Age cannot be negative!" << std::endl;
        return false;
    }

    if (age < 18)
    {
        std::cerr << "You must be at least 18!" << std::endl;
        return false;
    }

    return true;
}

int main()
{
    int age{-4};

    bool isValid = validateAge(age, std::cout);

    std::cout << "Valid: " << isValid << std::endl;
}
