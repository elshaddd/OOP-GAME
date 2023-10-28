#ifndef GAME_H
#define GAME_H
#include "../Player/Player.h"
#include "../Field/Field.h"
#include "../Control/PlayerController.h"
#include "../Input/InputHandler/InputHandler.h"
#include "../Input/InputSource/InputSource.h"
#include "../Generators/FieldGenerator.h"
#include "../Events/Visitor/EventSymbolVisitor.h"

class Game
{
private:
    
    // InputSource *inputSource;

    GameField gameField;
    Player player;
    PlayerController controller;
    InputHandler inputHandler;
    int level = 1;
    // Дополнительные члены класса...

public:
    Game(InputSource *inputSource);

    void leveling();

    void display();

    void start();

    void exit();

    void selectLevel(int level);

    bool checkGameStatus();

    void restart();

    void quit();

    void gameLoop();
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