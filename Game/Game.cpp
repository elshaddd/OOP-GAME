#include "Game.h"

Game::Game(Player &player, GameField &gameField, PlayerController &controller) : player(player), gameField(gameField), controller(controller) {}

void Game::leveling()
{
    if (level % 2 == 0)
    {
        gameField.resize((level * MIN_WIDTH) + 1, (level * MIN_HEIGHT) + 1);
    }
    else
    {
        gameField.resize(level * MIN_WIDTH, level * MIN_HEIGHT);
    }
    FieldGenerator generator(gameField);
    generator.generateField();
    controller.setCoordinates({1, 1});
}

void Game::start()
{
    if (gameStatus == MENU)
    {
        setStatus(RUN);
        player = Player();
        leveling();
    }
}

void Game::restart()
{
    if (gameStatus == OVER || gameStatus == PAUSE)
    {
        setStatus(RUN);
        player = Player();
        leveling();
    }
}

void Game::select()
{
    if (gameStatus == MENU)
    {
        setStatus(SELECTING);
    }
}

void Game::selectLevel(int level)
{
    if (gameStatus == SELECTING)
    {
        this->level = level;
        leveling();
    }
}

void Game::quit()
{
    if (gameStatus == SELECTING)
        setStatus(MENU);
    else if (gameStatus == PAUSE || gameStatus == WIN)
        setStatus(RUN);
    else if (gameStatus == RUN)
        setStatus(PAUSE);
}

void Game::menu()
{
    if (gameStatus == PAUSE || gameStatus == OVER || gameStatus == WIN)
    {
        setStatus(MENU);
    }
}

void Game::exit()
{
    if (gameStatus == MENU)
    {
        setStatus(EXIT);
    }
}

void Game::nextLevel()
{
    level++;
    leveling();
}

void Game::reset()
{
    player = Player();
    level = 1;
    leveling();
}

void Game::updateStatus()
{
    if (player.getHealth() == 0)
        setStatus(OVER);
    else if (controller.getCoordinates() == gameField.getExit())
        if (level == 4)
        {
            setStatus(WIN);
            reset();
        }
        else
            nextLevel();
}

Status Game::getStatus()
{
    return gameStatus;
}

void Game::setStatus(Status newStatus)
{
    gameStatus = newStatus;
    notify();
}

void Game::attach(Observer *obs)
{
    views.push_back(obs);
}

void Game::notify()
{
    for (const auto &obs : views)
        obs->update();
}
