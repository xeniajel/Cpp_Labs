// Активный бафф. Игрок хранит указатель на активный бафф. 
// Отсутствие баффа означает пустой указатель. 
// Дайте игроку 1 бафф на щит до боя и заберите его после боя.

struct Buff{};

struct Player{
    Buff* buff;
};

void give_buff(Player& player, Buff& buff)
{
    player.buff = &buff;
}

void remove_buff(Player& player)
{
    player.buff = nullptr;
}