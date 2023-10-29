#ifndef GAME_H
#define GAME_H
#include "IGame.h"
#include "../Player/Player.h"
#include "../Field/Field.h"
#include "../Util/Enums.h"
#include "../Control/PlayerController.h"
#include "../Input/InputHandler/InputHandler.h"
#include "../Input/InputSource/InputSource.h"
#include "../Generators/FieldGenerator.h"
#include "../Events/Visitor/EventSymbolVisitor.h"

class Game : public IGame
{
private:
    GameField gameField;
    Player player;
    PlayerController controller;
    InputHandler inputHandler;
    int level = 1;

public:
    Game(InputSource *inputSource);

    void leveling();

    void display();

    void start();

    void exit();

    void selectLevel(int level);

    Status checkGameStatus();

    // void restart();

    void quit() override;

    void gameLoop();

    void runMenu();

    void displayOver();

    void displayPass();

    void notRun(Status st);
};

// class Game
// {
// private:
//     Player player;
//     GameField gameField;
//     PlayerController playerController;
//     int level;

// public:
//     Game();  // Конструктор, инициализирующий игру
//     ~Game(); // Деструктор, освобождающий ресурсы

//     void startGame(); // Запускает игру, инициализируя игровое поле и игрока
//     void endGame();   // Завершает игру, освобождая ресурсы

//     void selectLevel(int level); // Выбирает уровень игры

//     void movePlayer(Direction direction); // Перемещает игрока в заданном направлении

//     void checkGameStatus(); // Проверяет статус игры (проигрыш или выигрыш)

//     void startNewGame(); // Начинает новую игру

//     void exitGame(); // Завершает работу программы
// };

#endif