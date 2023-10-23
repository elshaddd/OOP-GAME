#include <iostream>
#include "Player/Player.h"
#include "Field/Field.h"
#include "Control/PlayerController.h"
#include "Generators/FieldGenerator.h"
#include "Util/DisplayAndLeveling.h"
#include <termios.h>
#include <unistd.h>

int main()
{
    GameField gameField;
    int level = 1;
    Player player(100, 50, 50);
    PlayerController controller(player, gameField);
    {
        FieldGenerator generator(gameField);
        generator.generateField();
    }
    system("clear");
    std::cout << "HP: " << player.getHealth() << ' ' << "SCORE: " << player.getScore() << " DAMAGE: " << player.getDamage() << '\n';
    display(gameField, controller, level);
    char f = ' ';
    struct termios old_tio, new_tio;
    tcgetattr(STDIN_FILENO, &old_tio);
    new_tio = old_tio;
    new_tio.c_lflag &=(~ICANON & ~ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);

    while (f != '`')
    {
        f = getchar();
        std::cout << player.getHealth() << ' ' << player.getScore() << ' ' << player.getDamage() << '\n';
        switch (f)
        {
        case 'w':
            system("clear");
            std::cout << "HP: " << player.getHealth() << " SCORE: " << player.getScore() << " DAMAGE: " << player.getDamage() << '\n';
            controller.movePlayer(UP);
            std::cout << "HP: " << player.getHealth() << " SCORE: " << player.getScore() << " DAMAGE: " << player.getDamage() << '\n';
            display(gameField, controller, level);
            break;
        case 's':
            system("clear");
            std::cout << "HP: " << player.getHealth() << " SCORE: " << player.getScore() << " DAMAGE: " << player.getDamage() << '\n';
            controller.movePlayer(DOWN);
            std::cout << "HP: " << player.getHealth() << " SCORE: " << player.getScore() << " DAMAGE: " << player.getDamage() << '\n';
            display(gameField, controller, level);
            break;
        case 'a':
            system("clear");
            std::cout << "HP: " << player.getHealth() << " SCORE: " << player.getScore() << " DAMAGE: " << player.getDamage() << '\n';
            controller.movePlayer(LEFT);
            std::cout << "HP: " << player.getHealth() << " SCORE: " << player.getScore() << " DAMAGE: " << player.getDamage() << '\n';
            display(gameField, controller, level);
            break;
        case 'd':
            system("clear");
            std::cout << "HP: " << player.getHealth() << " SCORE: " << player.getScore() << " DAMAGE: " << player.getDamage() << '\n';
            controller.movePlayer(RIGHT);
            std::cout << "HP: " << player.getHealth() << " SCORE: " << player.getScore() << " DAMAGE: " << player.getDamage() << '\n';
            display(gameField, controller, level);
            break;
        default:
            break;
        }
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);
}