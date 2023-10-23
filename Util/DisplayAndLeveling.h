#include "../Control/PlayerController.h"
#include "../Generators/FieldGenerator.h"

void leveling(GameField &gameField, PlayerController &controller, int &level)
{
    if (level % 2 == 0)
    {
        gameField.resize((level * 23) + 1, (level * 11) + 1);
    }
    else
    {
        gameField.resize(level * 23, level * 11);
    }
    {
        FieldGenerator generator(gameField);
        generator.generateField();
    }
    controller.setCoordinates({1, 1});
}

void display(GameField &gameField, PlayerController &controller, int &level)
{
    for (int i = 0; i < gameField.getHeight(); i++)
    {
        for (int j = 0; j < gameField.getWidth(); j++)
        {
            if (controller.getCoordinates().first == j && controller.getCoordinates().second == i)
            {
                std::cout << "p" << ' ';
                if (controller.getCoordinates() == gameField.getExit())
                {
                    leveling(gameField, controller, ++level);
                }
            }
            else if (std::make_pair(j, i) == gameField.getEntrance())
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