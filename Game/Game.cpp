#include "Game.h"

/**
 * The Game constructor initializes a Game object with references to a Player, GameField, and
 * PlayerController.
 * 
 * @param player The player object represents the player in the game. It contains information about the
 * player's name, score, and other relevant data.
 * @param gameField The gameField parameter is an object of the GameField class. It represents the game
 * field or board where the game is played.
 * @param controller The controller parameter is an instance of the PlayerController class. It is
 * responsible for handling player input and controlling the player's actions in the game.
 */
Game::Game(Player &player, GameField &gameField, PlayerController &controller) : player(player), gameField(gameField), controller(controller) {}

/**
 * The leveling function resizes the game field based on the current level and generates a new field
 * using a FieldGenerator object, then sets the player's starting coordinates to (1, 1) using the
 * controller object.
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
 * The start function sets the game status to "RUN", initializes a player object, and calls the
 * leveling function.
 */
void Game::start()
{
    if (gameStatus == MENU)
    {
        gameStatus = RUN;
        player = Player();
        leveling();
    }
}

/**
 * The restart function resets the game status, creates a new player object, and calls the leveling
 * function.
 */
void Game::restart()
{
    if (gameStatus == OVER || gameStatus == PAUSE)
    {
        gameStatus = RUN;
        player = Player();
        leveling();
    }
}

/**
 * The select function changes the game status to SELECTING if the current game status is MENU.
 */
void Game::select()
{
    if (gameStatus == MENU)
        gameStatus = SELECTING;
}

/**
 * The selectLevel function sets the level of the game and calls the leveling function if the game
 * status is currently set to SELECTING.
 * 
 * @param level The level parameter is an integer that represents the level that the player wants to
 * select.
 */
void Game::selectLevel(int level)
{
    if (gameStatus == SELECTING)
    {
        this->level = level;
        leveling();
    }
}

/**
 * The quit function changes the game status between MENU, PAUSE, and RUN depending on the current game
 * status.
 */
void Game::quit()
{
    if (gameStatus == SELECTING)
        gameStatus = MENU;
    else if (gameStatus == PAUSE)
        gameStatus = RUN;
    else if (gameStatus == RUN)
        gameStatus = PAUSE;
    else if (gameStatus == WIN)
        gameStatus = RUN;    
}

/**
 * The menu function sets the game status to MENU if the current game status is PAUSE or OVER.
 */
void Game::menu()
{
    if (gameStatus == PAUSE || gameStatus == OVER || gameStatus == WIN)
        gameStatus = MENU;
}

void Game::exit()
{
    if(gameStatus == MENU)
        gameStatus = EXIT;
}

void Game::nextLevel()
{
    level++;
    leveling();
}

/**
 * The reset function resets the player and level variables to their initial values.
 */
void Game::reset()
{
    player = Player();
    level = 1;
    leveling();
}

/**
 * The function checks if the player's health is zero or if the player has reached the exit
 * coordinates, and updates the game status accordingly.
 */
void Game::checkRun()
{
    if (player.getHealth() == 0)
        gameStatus = OVER;
    else if (controller.getCoordinates() == gameField.getExit())
        if(level == 4)
            gameStatus = WIN;
        else 
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
 * The function sets the status of the game to a new status.
 * 
 * @param newStatus The new status that will be assigned to the game.
 */
void Game::setStatus(Status newStatus)
{
    gameStatus = newStatus;
}