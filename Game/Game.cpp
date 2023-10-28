#include "Game.h"

Game::Game(InputSource *inputSource) : gameField(), player(), controller(player, gameField), inputHandler(controller, *inputSource)
{
    FieldGenerator generator(gameField);
    generator.generateField();
}

void Game::leveling()
{
    level++;
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

void Game::display()
{
    std::cout << "HP: " << player.getHealth() << ' ' << "SCORE: " << player.getScore() /*<< " DAMAGE: "<< player.getDamage()*/ << '\n';
    std::string buffer;
    for (int i = 0; i < gameField.getHeight(); i++)
    {
        for (int j = 0; j < gameField.getWidth(); j++)
        {
            if (controller.getCoordinates().first == j && controller.getCoordinates().second == i)
            {
                buffer += "i ";
                if (controller.getCoordinates() == gameField.getExit())
                {
                    leveling();
                }
            }
            else if (std::make_pair(j, i) == gameField.getEntrance())
            {
                buffer += "] ";
            }
            else if (std::make_pair(j, i) == gameField.getExit())
            {
                buffer += "[ ";
            }
            else if (gameField.getCell(std::make_pair(j, i)).getEvent() != nullptr)
            {
                EventSymbolVisitor visitor;
                char symbol = gameField.getCell(std::make_pair(j, i)).getEvent()->accept(visitor);
                buffer += symbol;
                buffer += " ";
            }
            else if (gameField.getCell(std::make_pair(j, i)).isPassable())
            {
                buffer += "  ";
            }

            else
            {
                buffer += "* ";
            }
        }
        buffer += "\n";
    }
    std::cout << buffer;
}

void Game::start()
{
    // // инициализация игрового поля и установка начального положения игрока
    // controller.resetPlayerPosition();
    // gameLoop();
}

void Game::exit()
{
    // завершение текущей игры
    // очистка ресурсов...
}

void Game::selectLevel(int level)
{
    // установка уровня сложности
    // может включать изменение параметров gameField и controller
}

bool Game::checkGameStatus()
{
    // проверка условий выигрыша или проигрыша
    // может использовать методы Player и GameField
    return true;
}

void Game::restart()
{
    // перезапуск игры
    start();
}

void Game::quit()
{
    // выход из программы
    exit();
}

void Game::gameLoop()
{
    system("cls");
    display();
    while (true)
    {
        Command *command = inputHandler.handleInput();
        if (command)
        {
            command->execute();
        }
        system("cls");

        // // проверка на окончание игры
        // if (/* условие окончания игры */)
        // {
        //     // если игра окончена, выйти из цикла
        //     break;
        // }

        // обновление состояния игрового поля и игрока
        // ...

        // отрисовка игрового поля
        display();
    }

    // // проверка на выигрыш или проигрыш
    // checkGameStatus();

    // // предложение пользователю начать новую игру или выйти
    // char decision;
    // std::cout << "Game over. Start a new game (n) or quit (q)?";
    // std::cin >> decision;
    // if (decision == 'n')
    // {
    //     restart();
    // }
    // else if (decision == 'q')
    // {
    //     quit();
    // }
}