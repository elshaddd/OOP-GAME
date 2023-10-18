#include <iostream>
#include "Player.h"
#include "Field.h"
#include "PlayerController.h"
#include "FieldGenerator.h"

int main()
{
    Player player(50, 0, 40);
    GameField gameField;

    {
        FieldGenerator generator(gameField);
        generator.generateMaze();
    }
    // generator.printMaze();
    gameField.printMaze();
    std::pair<int, int> en = gameField.getEntrance();
    std::cout << en.first << ' ' << en.second << "\n";
    std::pair<int, int> ex = gameField.getExit();
    std::cout << ex.first << ' ' << ex.second << "\n";

    // std::cout << gameField.valid({100, 100}) << ' ' << gameField.valid({-10, -10}) << '\n';
    // std::cout << gameField.getCell({10, 10}).isPassable() << ' ' << gameField.getCell({0, 10}).isPassable() << '\n';
    // gameField.setEntrance({0, 1});

    // PlayerController controller(player,gameField);
    // std::cout << controller.getCoordinates().first << ' ' << controller.getCoordinates().second << "\n";
    // controller.movePlayer(UP);
    // std::cout << controller.getCoordinates().first << ' ' << controller.getCoordinates().second << "\n";
    // controller.movePlayer(RIGHT);
    // std::cout << controller.getCoordinates().first << ' ' << controller.getCoordinates().second << "\n";
    // controller.movePlayer(UP);
    // std::cout << controller.getCoordinates().first << ' ' << controller.getCoordinates().second << "\n";
    // controller.movePlayer(DOWN);
    // std::cout << controller.getCoordinates().first << ' ' << controller.getCoordinates().second << "\n";
    // return 0;
}