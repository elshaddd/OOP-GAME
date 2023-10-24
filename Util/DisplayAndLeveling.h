#ifndef DISPLAY_AND_LEVEL_H
#define DISPLAY_AND_LEVEL_H

#include "../Control/PlayerController.h"
#include "../Generators/FieldGenerator.h"
#include "../Events/Visitor/EventSymbolVisitor.h"

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
    std::string buffer;
    for (int i = 0; i < gameField.getHeight(); i++)
    {
        for (int j = 0; j < gameField.getWidth(); j++)
        {
            if (controller.getCoordinates().first == j && controller.getCoordinates().second == i)
            {
                buffer += "i "; //\uD83d\uDE4D 
                if (controller.getCoordinates() == gameField.getExit())
                {
                    leveling(gameField, controller, ++level);
                }
            }
            else if (std::make_pair(j, i) == gameField.getEntrance())
            {
                buffer += "] ";
            }
            else if (std::make_pair(j, i) == gameField.getExit())
            {
                buffer += "[ ";
            }
            else if (gameField.getCell(std::make_pair(j, i)).getEvent() != nullptr)
            {
                // buffer += "? ";
                EventSymbolVisitor visitor;
                // char symbol = gameField.getCell(std::make_pair(j, i)).getEvent()->accept(visitor);
                buffer += gameField.getCell(std::make_pair(j, i)).getEvent()->accept(visitor);
                buffer += " ";
            }
            else if (gameField.getCell(std::make_pair(j, i)).isPassable())
            {
                buffer += "  ";
            }

            else
            {
                buffer += "* ";
            }
        }
        buffer += "\n";
    }
    std::cout << buffer;
}

#endif