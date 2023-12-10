#ifndef PLAYER_H
#define PLAYER_H

#include <algorithm>

class Player
{
private:
    int health;
    int score;
    // int damage;

public:
    // Player();

    Player(int initHealth = 100, int initScore = 50/*, int initDamage = 5*/);

    // Метод выравнивания характеристик по диапазону
    int normalization(int val, int lowerLimit, int upperLimit);

    // Метод получения здоровья 
    int getHealth();

    // Метод получения счета 
    int getScore();

    // Метод получения кол-ва урона 
    // int getDamage();

    // Метод изменения здоровья 
    void setHealth(int newHealth);

    // Метод изменения счета 
    void setScore(int newScore);

    // Метод изменения кол-ва урона 
    // void setDamage(int newDamage);
};

#endif