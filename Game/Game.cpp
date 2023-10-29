#include "Game.h"

Game::Game(InputSource *inputSource) : gameField(), player(), controller(player, gameField), inputHandler(controller, *inputSource, [this]()
                                                                                                          { this->quit(); }) {}

void Game::createLevel()
{
    FieldGenerator generator(gameField);
    generator.generateField();
    controller.setCoordinates({1, 1});
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
    createLevel();
}

void Game::start()
{
    level = 1;
    createLevel();
    gameLoop();
}

void Game::quit()
{
    runMenu();
    // int choice;
    // while(true){
        
    // }
    // do
    // {
    //     system("cls");
    //     std::cout << "1. Start game\n";
    //     std::cout << "2. Select level\n";
    //     std::cout << "3. Quit\n";
    //     std::cout << ">> ";
    //     std::cin >> choice;

    //     switch (choice)
    //     {
    //     case 1:
    //         start();
    //         break;
    //     case 2:
    //         std::cout << "Enter level: ";
    //         int level;
    //         std::cin >> level;
    //         selectLevel(level);
    //         break;
    //     case 3:
    //         exit();
    //         break;
    //     default:
    //         std::cout << "Invalid choice. Please try again.\n";
    //     }
    // } while (choice != 3);
}

void Game::selectLevel(int level)
{
    this->level = level;
    leveling();
}

Status Game::checkGameStatus()
{
    if (player.getHealth() == 0)
        return OVER;
    else if (controller.getCoordinates() == gameField.getExit())
        return PASS;
    else
        return RUN;
}

void Game::exit()
{
    std::exit(0);
}

void Game::notRun(Status st)
{
    if (st == OVER)
        displayOver();
    else
        displayPass();
}

void Game::gameLoop()
{
    display();
    while (true)
    {
        Command *command = inputHandler.handleInput();
        if (command)
        {
            command->execute();
        }

        // отрисовка игрового поля
        display();

        if (checkGameStatus() != RUN)
        {
            notRun(checkGameStatus());
            break;
        }
    }
}

void Game::display()
{
    system("cls");
    std::cout << "HP: " << player.getHealth() << ' ' << "SCORE: " << player.getScore() /*<< " DAMAGE: "<< player.getDamage()*/ << '\n';
    std::string buffer;
    for (int i = 0; i < gameField.getHeight(); i++)
    {
        for (int j = 0; j < gameField.getWidth(); j++)
        {
            if (controller.getCoordinates().first == j && controller.getCoordinates().second == i)
            {
                buffer += "i ";
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

void Game::runMenu()
{
    int choice;
    do
    {
        system("cls");
        std::cout << "1. Start game\n";
        std::cout << "2. Select level\n";
        std::cout << "3. Quit\n";
        std::cout << ">> ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            start();
            break;
        case 2:
            std::cout << "Enter level: ";
            int level;
            std::cin >> level;
            selectLevel(level);
            break;
        case 3:
            exit();
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);
}

void Game::displayOver()
{
    // предложение пользователю начать новую игру или выйти
    char decision;
    do
    {
        system("cls");
        std::cout << "GAME OVER\nStart a new game (n) or quit (q)?\n>> ";
        std::cin >> decision;

        switch (decision)
        {
        case 'n':
            controller.modifyHealth(100);
            selectLevel(1);
            start();
            break;
        case 'q':
            quit();
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (true);
}

void Game::displayPass()
{
    // предложение пользователю начать новую игру или выйти
    char decision;
    do
    {
        system("cls");
        std::cout << "YOU PASSED THE LEVEL\nNext level (n) or quit (q)?\n>> ";
        std::cin >> decision;

        switch (decision)
        {
        case 'n':
            selectLevel(++level);
            gameLoop();
            break;
        case 'q':
            quit();
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (true);
}