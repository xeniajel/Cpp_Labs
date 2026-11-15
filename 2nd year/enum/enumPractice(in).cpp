#include <iostream>

enum class Portrait
{
    LENIN,
    WASHINGTON,
    HITLER,
};

enum class BulbColor
{
    BLUE,
    WHITE,
    RED,
};

enum class WireColor
{
    RED,
    YELLOW,
    GREEN,
};

struct BombCharacteristics
{
    Portrait portrait;
    BulbColor bulbColor;
    bool switchOn;
    int dialValue;
};

struct BombDefusionDecision
{
    bool shouldDefuse;
    WireColor wire;
};

int getBulbColorValue(BulbColor bulbColor)
{
    int bulbColorValue;

    switch (bulbColor)
    {
    case BulbColor::BLUE:
    {
        bulbColorValue = 11;
        break;
    }
    case BulbColor::WHITE:
    {
        bulbColorValue = 15;
        break;
    }
    case BulbColor::RED:
    {
        bulbColorValue = 35;
        break;
    }
    }
    return bulbColorValue;
}

BombDefusionDecision takeDecision(BombCharacteristics bomb)
{
    BombDefusionDecision decision{};
    if (bomb.portrait == Portrait::LENIN)
    {
        return decision;
    }

    BulbColor currentBulbColor = bomb.bulbColor;

    if (bomb.portrait == Portrait::HITLER)
    {
        currentBulbColor = static_cast<BulbColor>((static_cast<int>(bomb.bulbColor) + 1) % 3);
    }

    int bulbColorValue = getBulbColorValue(currentBulbColor);

    if (bomb.dialValue == bulbColorValue)
    {
        decision = {true, WireColor::GREEN};
    }
    else if (bomb.dialValue < bulbColorValue)
    {
        decision = {true, WireColor::RED};
    }
    else
    {
        decision = {true, WireColor::YELLOW};
    }

    WireColor currentWire = decision.wire;

    if (bomb.switchOn == true)
    {
        currentWire = static_cast<WireColor>((static_cast<int>(currentWire) - 1 + 3) % 3);
    }

    if (bomb.dialValue % 4 == 0)
    {
        currentWire = static_cast<WireColor>((static_cast<int>(currentWire) + bomb.dialValue) % 3);
    }

    decision.wire = currentWire;

    return decision;
}

int main()
{
    int portraitInput;
    std::cout << "Choose the portrait: 0 - Lenin, 1 - Washington, 2 - Hitler" << std::endl;

    while (true)
    {
        std::cin >> portraitInput;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');

            std::cout << "Invalid input. Enter a number: ";
            continue;
        }

        if (portraitInput < 0 || portraitInput > 2)
        {
            std::cout << "Invalid number. Try again: ";
            continue;
        }

        break;
    }

    Portrait inputPortrait = static_cast<Portrait>(portraitInput);

    int bulbInput;

    std::cout << "Choose bulb color: 0 - Blue, 1 - White, 2 - Red" << std::endl;

    while (true)
    {
        std::cin >> bulbInput;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');

            std::cout << "Invalid input. Enter a number: ";
            continue;
        }

        if (bulbInput < 0 || bulbInput > 2)
        {
            std::cout << "Invalid number. Try again: ";
            continue;
        }

        break;
    }

    BulbColor inputBulbColor = static_cast<BulbColor>(bulbInput);

    int switchInput;

    std::cout << "Switch state: 0 - OFF, 1 - ON" << std::endl;

    while (true)
    {
        std::cin >> switchInput;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');

            std::cout << "Invalid input. Enter 0 or 1: ";
            continue;
        }

        if (switchInput != 0 && switchInput != 1)
        {
            std::cout << "Invalid input. Enter 0 or 1: ";
            continue;
        }

        break;
    }

    bool inputSwitch = static_cast<bool>(switchInput);

    int dialInput;

    std::cout << "Enter dial value (1-150): " << std::endl;

    while (true)
    {
        std::cin >> dialInput;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');

            std::cout << "Invalid input. Enter a number: ";
            continue;
        }

        if (dialInput < 1 || dialInput > 150)
        {
            std::cout << "Invalid number. Try again: ";
            continue;
        }

        break;
    }

    BombCharacteristics inputBomb{
        inputPortrait,
        inputBulbColor,
        inputSwitch,
        dialInput};

    BombDefusionDecision result = takeDecision(inputBomb);

    if (!result.shouldDefuse)
    {
        std::cout << "No wire should be cut!" << std::endl;
    }
    else
    {
        std::cout << "Defuse the bomb! Cut the ";

        switch (result.wire)
        {
        case WireColor::RED:
            std::cout << "RED wire";
            break;

        case WireColor::YELLOW:
            std::cout << "YELLOW wire";
            break;

        case WireColor::GREEN:
            std::cout << "GREEN wire";
            break;
        }

        std::cout << "!" << std::endl;
    }
}