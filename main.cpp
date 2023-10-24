#include <iostream>
#include "Player/Player.h"
#include "Field/Field.h"
#include "Control/PlayerController.h"
#include "Generators/FieldGenerator.h"
#include "Util/DisplayAndLeveling.h"
#ifndef LIN
#include <conio.h>
#else
#include <termios.h>
#endif

int main()
{
    GameField gameField;
    Player player(60, 50, 50);
    PlayerController controller(player, gameField);
    {
        FieldGenerator generator(gameField);
        generator.generateField();
    }
    int level = 1;
    #ifndef LIN
    system("cls");
    #else
    system("clear");
    #endif
    std::cout << "HP: " << player.getHealth() << ' ' << "SCORE: " << player.getScore() << " DAMAGE: " << player.getDamage() << '\n';
    display(gameField, controller, level);
    char f = ' ';
    #ifdef LIN
    struct termios old_tio, new_tio;
    tcgetattr(STDIN_FILENO, &old_tio);
    new_tio = old_tio;
    new_tio.c_lflag &=(~ICANON & ~ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);
    #endif
    while (f != '`')
    {
        #ifndef LIN
        f = getch();
        system("cls");
        #else
        f = getchar();
        system("clear");
        #endif
        switch (f)
        {
        case 'w':
            controller.movePlayer(UP);
            break;
        case 's':
            controller.movePlayer(DOWN);
            break;
        case 'a':
            controller.movePlayer(LEFT);
            break;
        case 'd':
            controller.movePlayer(RIGHT);
            break;
        default:
            break;
        }
        std::cout << "HP: " << player.getHealth() << " SCORE: " << player.getScore() << " DAMAGE: " << player.getDamage() << '\n';
        display(gameField, controller, level);
    }
    #ifdef LIN
    tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);
    #endif
}