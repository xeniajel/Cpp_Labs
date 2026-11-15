// Выпить зелье. У героя есть здоровье и щит.
// Зелье бывает красным, синим или испорченным.
// Дайте герою 1 красное зелье.
// Красное добавляет 20 здоровья, синее добавляет 10 щита, испорченное ничего не делает.
#include <string_view>

struct Hero
{
    int health;
    int shield;
};

enum class PotionKind
{
    RED,
    BLUE,
    SPOILED,
};

struct Potion
{
    PotionKind kind;
};

bool drink_potion(Hero &hero, Potion potion)
{
    switch (potion.kind)
    {
    case PotionKind::RED:
        hero.health += 20;
        return true;
    case PotionKind::BLUE:
        hero.shield += 10;
        return true;
    case PotionKind::SPOILED:
        return false;
    }
    return false;
}

int main()
{
    Hero hero{.health = 50, .shield = 0};
    drink_potion(hero, Potion{.kind = PotionKind::RED});
}