#include "Game.h"

/**
 * The Game constructor initializes a Game object with references to a Player, GameField, and
 * PlayerController.
 * 
 * @param player The player object that represents the player in the game.
 * @param gameField The gameField parameter is an object of the GameField class. It represents the game
 * field or board where the game is played.
 * @param controller The `controller` parameter is an object of the `PlayerController` class. It is
 * used to control the actions and movements of the player in the game.
 */
Game::Game(Player &player, GameField &gameField, PlayerController &controller) : player(player), gameField(gameField), controller(controller) {}

/**
 * The `leveling` function resizes the game field based on the current level and generates a new field
 * using a `FieldGenerator` object, and sets the player's starting coordinates to (1, 1).
 */
void Game::leveling()
{
    if (level % 2 == 0)
    {
        gameField.resize((level * 23) + 1, (level * 11) + 1);
    }
    else
    {
        gameField.resize(level * 23, level * 11);
    }
    FieldGenerator generator(gameField);
    generator.generateField();
    controller.setCoordinates({1, 1});
}

/**
 * The start function sets the game status to "RUN" and calls the leveling function if the game status
 * is either "PAUSE" or "PASS".
 */
void Game::start()
{
    if (gameStatus == PAUSE || gameStatus == PASS)
    {
        gameStatus = RUN;
        leveling();
    }
}

/**
 * The restart function resets the game status to "RUN", sets the level to 1, and calls the leveling
 * function.
 */
void Game::restart()
{
    if (gameStatus == OVER)
    {
        gameStatus = RUN;
        level = 1;
        leveling();
    }
}

/**
 * The selectLevel function sets the level of the game if the game is currently paused.
 * 
 * @param level The level parameter is an integer that represents the level that the player wants to
 * select.
 */
void Game::selectLevel(int level)
{
    if (gameStatus == PAUSE)
    {
        this->level = level;
        leveling();
    }
}

/**
 * The quit function sets the game status to PAUSE.
 */
void Game::quit()
{
    gameStatus = PAUSE;
}

// can use in Client

/**
 * The function "nextLevel" increases the level by one and calls the "leveling" function.
 */
void Game::nextLevel()
{
    level++;
    leveling();
}

/**
 * The reset function resets the game by creating a new player object and setting the level to 1.
 */
void Game::reset()
{
    player = Player();
    level = 1;
}

/**
 * The function checks if the player's health is zero or if the player's coordinates match the exit
 * coordinates, and updates the game status accordingly.
 */
void Game::checkRun()
{
    if (player.getHealth() == 0)
        gameStatus = OVER;
    else if (controller.getCoordinates() == gameField.getExit())
        gameStatus = PASS;
}

/**
 * The getStatus function returns the current status of the game.
 * 
 * @return The getStatus() function is returning the value of the gameStatus variable.
 */
Status Game::getStatus()
{
    return gameStatus;
}

/**
 * The function sets the game status to a new status.
 * 
 * @param newStatus The new status that will be assigned to the game.
 */
void Game::setStatus(Status newStatus)
{
    gameStatus = newStatus;
}

// /**
//  * The function "getLevel" returns the value of the variable "level".
//  * 
//  * @return The level of the game.
//  */
// int Game::getLevel()
// {
//     return level;
// }

// /**
//  * The function sets the level of the game to a new value.
//  * 
//  * @param newLevel The new level that you want to set for the game.
//  */
// void Game::setLevel(int newLevel)
// {
//     level = newLevel;
// }