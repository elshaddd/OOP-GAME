#include <iostream>
#include "Player.h"
#include "Field.h"
#include "PlayerController.h"
#include "FieldGenerator.h"

int main()
{
    Player player(50, 0, 40);
    GameField gameField(65, 33);

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
}