#include "GameClient.h"

/**
 * The GameClient constructor initializes a GameClient object with the given input source, player, game
 * field, controller, game, and input handler.
 *
 * @param inputSource The input source is an object that provides input to the game client. It could be
 * a keyboard, or any other file. The game client uses this input source to receive
 * user input and respond accordingly.
 */
GameClient::GameClient(InputSource *inputSource) : player(), gameField(), controller(player, gameField), game(player, gameField, controller), inputHandler(&controller, &game, *inputSource), display(player, gameField, controller) {}

/**
 * The loop function in the GameClient class continuously displays different menus and game screens
 * based on the current game status.
 */
void GameClient::loop()
{
    display.displayMenu();
    Invoker invoker;
    while (game.getStatus() != EXIT)
    {
        invoker.call(inputHandler.handleInput());
        game.updateStatus();
        switch (game.getStatus())
        {
        case MENU:
            display.displayMenu();
            break;
        case SELECTING:
            display.displaySelecting();
            break;
        case PAUSE:
            display.displayPause();
            break;
        case RUN:
            display.displayRun();
            break;
        case OVER:
            display.displayOver();
            break;
        case WIN:
            display.displayWin();
        }
    }
}