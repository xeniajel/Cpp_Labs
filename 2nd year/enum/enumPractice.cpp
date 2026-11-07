#include <iostream>
#include <cassert>

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
    BombCharacteristics bomb{Portrait::LENIN};
    BombDefusionDecision result = takeDecision(bomb);
    assert(result.shouldDefuse == false);

    BombCharacteristics bomb1{Portrait::WASHINGTON, BulbColor::BLUE, false, 11};
    BombDefusionDecision result1 = takeDecision(bomb1);
    assert(result1.shouldDefuse == true && result1.wire == WireColor::GREEN);

    BombCharacteristics bomb2{Portrait::WASHINGTON, BulbColor::BLUE, false, 10};
    BombDefusionDecision result2 = takeDecision(bomb2);
    assert(result2.shouldDefuse == true && result2.wire == WireColor::RED);

    BombCharacteristics bomb3{Portrait::WASHINGTON, BulbColor::WHITE, false, 15};
    BombDefusionDecision result3 = takeDecision(bomb3);
    assert(result3.shouldDefuse == true && result3.wire == WireColor::GREEN);

    BombCharacteristics bomb4{Portrait::WASHINGTON, BulbColor::RED, false, 40};
    BombDefusionDecision result4 = takeDecision(bomb4);
    assert(result4.shouldDefuse == true && result4.wire == WireColor::GREEN);

    BombCharacteristics bomb5{Portrait::HITLER, BulbColor::BLUE, false, 15};
    BombDefusionDecision result5 = takeDecision(bomb5);
    assert(result5.shouldDefuse == true && result5.wire == WireColor::GREEN);
}