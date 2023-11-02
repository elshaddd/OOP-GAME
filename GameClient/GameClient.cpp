#include "GameClient.h"

/**
 * The GameClient constructor initializes a GameClient object with the given input source, player, game
 * field, controller, game, and input handler.
 * 
 * @param inputSource The input source is an object that provides input to the game client. It could be
 * a keyboard, a mouse, or any other input device. The game client uses this input source to receive
 * user input and respond accordingly.
 */
GameClient::GameClient(InputSource *inputSource) : player(), gameField(), controller(player, gameField), game(player, gameField, controller), inputHandler(&controller, &game, *inputSource) {}

/**
 * The loop function in the GameClient class continuously displays different menus and game screens
 * based on the current game status.
 */
void GameClient::loop()
{
    displayMenu();
    Invoker invoker;
    while (true)
    {
        invoker.call(inputHandler.handleInput());
        game.checkRun();
        switch (game.getStatus())
        {
        case MENU:
            displayMenu();
            break;
        case SELECTING:
            displaySelecting();
            break;
        case PAUSE:
            displayPause();
            break;
        case RUN:
            displayRun();
            break;
        case OVER:
            displayOver();
            break;
        case PASS:
            game.setStatus(RUN);
            game.nextLevel();
            displayRun();
            break;
        }
    }
}

void GameClient::displayMenu()
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

void GameClient::displaySelecting()
{
#ifdef LIN
    system("clear");
#else
    system("cls");
#endif
    std::cout << "` - Back\n";
    std::cout << "z - First level   x - Second level   c - Third level   v - Fourth level\n";
}

void GameClient::displayPause()
{
#ifdef LIN
    system("clear");
#else
    system("cls");
#endif
    std::cout << "` - Resume\n";
    std::cout << "n - Restart\n";
    std::cout << "m - Menu\n";
}

void GameClient::displayRun()
{
    std::ostringstream buffer;
    buffer << "HP: " << player.getHealth() << ' ' << "SCORE: " << player.getScore() /*<< " DAMAGE: "<< player.getDamage()*/ << '\n';

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
    buffer << "Press (`) to pause\n";

#ifdef LIN
    system("clear");
#else
    system("cls");
#endif
    std::cout << buffer.str();
}

void GameClient::displayOver()
{
#ifdef LIN
    system("clear");
#else
    system("cls");
#endif
    std::cout << "GAME OVER\nRestart (n) or back to menu (m)?\n>> ";
}