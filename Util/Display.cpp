#include "Display.h"

Display::Display(Player &player, GameField &gameField, PlayerController &controller) : player(player), gameField(gameField), controller(controller) {}

void Display::displayMenu()
{
#ifdef LIN
    system("clear");
#else
    system("cls");
#endif
    std::cout << "1 - Start game\n";
    std::cout << "2 - Select level\n";
    std::cout << "0 - Exit\n";
}

void Display::displaySelecting()
{
#ifdef LIN
    system("clear");
#else
    system("cls");
#endif
    std::cout << "q - Back\n";
    std::cout << "z - First level   x - Second level   c - Third level   v - Fourth level\n";
}

void Display::displayPause()
{
#ifdef LIN
    system("clear");
#else
    system("cls");
#endif
    std::cout << "q - Resume\n";
    std::cout << "n - Restart\n";
    std::cout << "m - Menu\n";
}

void Display::displayRun()
{
    std::ostringstream buffer;
    buffer << "HP: " << player.getHealth() << ' ' << "COINS: " << player.getScore() /*<< " DAMAGE: "<< player.getDamage()*/ << '\n';

    for (int i = 0; i < gameField.getHeight(); i++)
    {
        for (int j = 0; j < gameField.getWidth(); j++)
        {
            if (controller.getCoordinates().first == j && controller.getCoordinates().second == i)
            {
                buffer << "i ";
            }
            else if (std::make_pair(j, i) == gameField.getEntrance())
            {
                buffer << "] ";
            }
            else if (std::make_pair(j, i) == gameField.getExit())
            {
                buffer << "[ ";
            }
            else if (gameField.getCell(std::make_pair(j, i)).getEvent() != nullptr)
            {
                EventSymbolVisitor visitor;
                char symbol = gameField.getCell(std::make_pair(j, i)).getEvent()->accept(visitor);
                buffer << symbol << " ";
            }
            else if (gameField.getCell(std::make_pair(j, i)).isPassable())
            {
                buffer << "  ";
            }
            else
            {
                buffer << "* ";
            }
        }
        buffer << "\n";
    }
    buffer << "Press (q) to pause\n";

#ifdef LIN
    system("clear");
#else
    system("cls");
#endif
    std::cout << buffer.str();
}

void Display::displayOver()
{
#ifdef LIN
    system("clear");
#else
    system("cls");
#endif
    std::cout << "GAME OVER\nRestart (n) or back to menu (m)?\n>> ";
}

void Display::displayWin()
{
#ifdef LIN
    system("clear");
#else
    system("cls");
#endif
    std::cout << "YOU WIN\nRestart game (q) or back to menu (m)?\n>> ";
}