#include <iostream>
#include "Player.h"
#include "Field.h"
#include "PlayerController.h"
#include "./Generators/FieldGenerator.h"

/**
 * The main function generates a game field and prints it out, with different symbols representing
 * different elements on the field.
 */
int main()
{
    GameField gameField;
    int numsOfLevels = 3;
    int k = 1;
    
    while (numsOfLevels)
    {

        if (k % 2 == 0)
        {
            gameField.resize((k * 23) + 1, (k * 11) + 1);
        }
        else
        {
            gameField.resize(k * 23, k * 11);
        }
        {
            FieldGenerator generator(gameField);
            generator.generateField();
        }
        for (int i = 0; i < gameField.getHeight(); i++)
        {
            for (int j = 0; j < gameField.getWidth(); j++)
            {
                if (std::make_pair(j, i) == gameField.getEntrance())
                {
                    std::cout << "]" << ' ';
                }
                else if (std::make_pair(j, i) == gameField.getExit())
                {
                    std::cout << "[" << ' ';
                }
                else if (gameField.getCell(std::make_pair(j, i)).getEvent() != nullptr)
                {
                    std::cout << "?" << ' ';
                }
                else if (gameField.getCell(std::make_pair(j, i)).isPassable())
                {
                    std::cout << " " << ' ';
                }
                else
                {
                    std::cout << "*" << ' ';
                }
            }
            std::cout << "\n";
        }
        k++;
        numsOfLevels--;
        std::cout << "Press enter to continue ...";
        std::cin.get();
    }
}