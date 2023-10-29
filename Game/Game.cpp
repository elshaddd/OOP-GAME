#include "Game.h"

Game::Game(InputSource *inputSource) : gameField(), player(), controller(player, gameField),
                                       inputHandler(
                                           controller, *inputSource,
                                           [this]()
                                           { this->start(); },
                                           [this]()
                                           { this->restart(); },
                                           [this](int level)
                                           { this->selectLevel(level); },
                                           [this]()
                                           { this->quit(); })
{
}

void Game::process()
{
    displayMenu();
    while (gameStatus == PAUSE)
    {
        Command *command = inputHandler.handleInput();
        if (command)
        {
            command->execute();
        }
    }
}

void Game::gameLoop()
{
    display();
    while (gameStatus == RUN)
    {
        Command *command = inputHandler.handleInput();
        if (command)
        {
            command->execute();
        }
        display();
        checkRun();
        if (gameStatus == OVER)
        {
            gameOver();
        }
        else if (gameStatus == PASS)
        {
            level++;
            start();
        }
    }
}

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

void Game::start()
{
    if(gameStatus == PAUSE || gameStatus == PASS)
    {
        gameStatus = RUN;
        leveling();
        gameLoop();
    }
}

void Game::restart()
{
    if(gameStatus == OVER){
        gameStatus = RUN;
        level = 1;
        leveling();
        gameLoop();
    }
}

void Game::selectLevel(int level)
{
    if(gameStatus == PAUSE){
        this->level = level;
        leveling();
    }
}

void Game::quit()
{
    gameStatus = PAUSE;
    process();
}

void Game::checkRun()
{
    if (player.getHealth() == 0)
        gameStatus = OVER;
    else if (controller.getCoordinates() == gameField.getExit())
        gameStatus = PASS;
}

void Game::gameOver()
{
    displayOver();
    player = Player();
    level = 1;
    while (gameStatus == OVER)
    {
        Command *command = inputHandler.handleInput();
        if (command)
        {
            command->execute();
        }
    }
}

void Game::displayMenu()
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

void Game::display()
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

void Game::displayOver()
{
    #ifdef LIN
    system("clear");
    #else
    system("cls");
    #endif
    std::cout << "GAME OVER\nStart a new game (n) or quit (m)?\n>> ";
}