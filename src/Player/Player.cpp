#include "Player.h"

Player::Player(int initHealth, int initScore/*, int initDamage*/)
{
    health = normalization(initHealth, 1, 100); // Невозможно создать игрока с 0 hp
    score = normalization(initScore, 0, __INT_MAX__);
    // damage = normalization(initDamage, 5, 100);
}

int Player::normalization(int val, int lowerLimit, int upperLimit)
{
    val = std::max(lowerLimit, val);
    val = std::min(upperLimit, val);
    return val;
}

int Player::getHealth()
{
    return health;
}

int Player::getScore()
{
    return score;
}

// int Player::getDamage()
// {
//     return damage;
// }

void Player::setHealth(int newHealth)
{
    health = normalization(newHealth, 0, 100);
}

void Player::setScore(int newScore)
{
    score = normalization(newScore, 0, __INT_MAX__);
}

// void Player::setDamage(int newDamage)
// {
//     damage = normalization(newDamage, 5, 100);
// }