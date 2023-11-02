#include "GameClient.h"

/**
 * The GameClient constructor initializes a GameClient object with the given input source, player, game
 * field, controller, game, and input handler.
 *
 * @param inputSource The input source is an object that provides input to the game client. It could be
 * a keyboard, mouse, or any other input device.
 */
GameClient::GameClient(InputSource *inputSource) : player(), gameField(), controller(player, gameField), game(player, gameField, controller), inputHandler(&controller, &game, *inputSource) {}

/**
 * The loop function in the GameClient class continuously displays menus, handles user input, updates
 * the game state, and displays the game until it is over or the player passes to the next level.
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
        case PAUSE:
            displayMenu();
            break;
        case RUN:
            display();
            break;
        case OVER:
            displayOver();
            game.reset();
            break;
        case PASS:
            game.setStatus(RUN);
            game.nextLevel();
            display();
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
    std::cout << "0 - Exit\n";
    std::cout << "z - First level   x - Second level   c - Third level   v - Fourth level\n";
}

void GameClient::display()
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
    buffer << "Press (m) to exit the level\n";

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
    std::cout << "GAME OVER\nStart a new game (n) or quit (m)?\n>> ";
}