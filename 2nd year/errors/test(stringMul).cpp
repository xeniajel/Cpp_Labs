
#include <iostream>

bool validateAge(int age, std::ostream& error)
{
    bool isValid = true;

    if (age < 0)
    {
        error << "Age cannot be negative!" << std::endl;
        isValid = false;
    }

    if (age < 18)
    {
        error << "You must be at least 18!" << std::endl;
        isValid = false;
    }

    return isValid;
}

int main()
{
    int age{-5};

    bool isValid = validateAge(age, std::cout);

    std::cout << "Valid: " << isValid << std::endl;
}
