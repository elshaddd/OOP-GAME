#include "Game.h"

Game::Game(Player &player, GameField &gameField, PlayerController &controller, MessageDispatcher *dispatcher) : player(player), gameField(gameField), controller(controller), dispatcher(dispatcher) {}

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
    setStatus(RUN);
}

void Game::start()
{
    if (gameStatus == MENU)
    {
        player = Player();
        leveling();
        setStatus(RUN);
    }
    if (dispatcher != nullptr)
    {
        StartMessage event(gameField);
        dispatcher->dispatchEvent(event);
    }
}

void Game::restart()
{
    if (gameStatus == OVER || gameStatus == PAUSE)
    {
        player = Player();
        leveling();
        setStatus(RUN);
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
    {
        reset();
        setStatus(OVER);
        if (dispatcher != nullptr)
        {
            LoseMessage event(controller);
            dispatcher->dispatchEvent(event);
        }
    }
    else if (controller.getCoordinates() == gameField.getExit())
    {
        if (level == 4)
        {
            reset();
            setStatus(WIN);
            if (dispatcher != nullptr)
            {
                WinMessage event(player);
                dispatcher->dispatchEvent(event);
            }
        }
        else
        {
            setStatus(PASS);
            nextLevel();
        }
    }
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

void Game::setMediator(Mediator *mediator)
{
    this->mediator = mediator;
}

void Game::notify()
{
    mediator->update(GAME);
}