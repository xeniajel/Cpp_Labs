#include <cmath>
#include <iostream>

struct Player{
    int energy;
    int lives;
};

struct LevelConfiguration{
    int energyPerLevel;
};

int complete_level (Player* player, LevelConfiguration config)
{
    int a{ player->lives };
    int b{ player->energy/config.energyPerLevel };
    int p {std::min(a, b)};
    int result{p};
    player->lives -= p;
    player->energy -= p * config.energyPerLevel;
    return result;
}

int main(){
    Player player{
        .energy = 75,
        .lives = 4,
    };

    LevelConfiguration config{
        .energyPerLevel = 20,
    };

    int finishedLevels{complete_level(&player, config) };

    std::cout 
        << "Finished " 
        << finishedLevels
        << " levels" 
        << std::endl;
    std::cout 
        << "Left "
        << player.energy 
        << " energy and " 
        << player.lives
        << " lives."
        << std::endl;
}