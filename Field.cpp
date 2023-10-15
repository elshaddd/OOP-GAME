#include "Field.h"

void GameField::normalization(int &width, int &height)
{
    width = std::max(MIN_WIDTH, width);
    width = std::min(MAX_WIDTH, width);

    height = std::max(MIN_HEIGHT, height);
    height = std::min(MAX_HEIGHT, height);
}

Cell **GameField::fieldAlloc(int width, int height)
{
    Cell **field = new Cell *[height];
    for (int i = 0; i < height; i++)
    {
        field[i] = new Cell[width];
    }
    return field;
}

GameField::GameField(int width, int height, int entranceX, int entranceY, int exitX, int exitY)
{
    normalization(width, height);
    this->width = width;
    this->height = height;
    field = fieldAlloc(width, height);
    if (valid(entranceX, entranceY))
        entrance = std::make_pair(entranceX, entranceY);
    if (valid(exitX, exitY))
        exit = std::make_pair(exitX, exitY);
}

GameField::GameField(const GameField &other) : width(other.width), height(other.height), entrance(other.entrance), exit(other.exit)
{
    field = fieldAlloc(width, height);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            field[i][j] = other.field[i][j];
    }
}

GameField::GameField(GameField &&other) noexcept : width(0), height(0), entrance(0, 0), exit(0, 0), field(nullptr)
{
    std::swap(width, other.width);
    std::swap(height, other.height);
    std::swap(field, other.field);
    std::swap(entrance, other.entrance);
    std::swap(exit, other.exit);
}

GameField &GameField::operator=(const GameField &other)
{
    for (int i = 0; i < height; ++i)
        delete[] field[i];
    delete[] field;
    width = other.width;
    height = other.height;
    field = fieldAlloc(width, height);
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
            field[i][j] = other.field[i][j];
    }
    return *this;
}

GameField &GameField::operator=(GameField &&other) noexcept
{
    if (this != &other)
    {
        for (int i = 0; i < height; ++i)
            delete[] field[i];
        delete[] field;

        std::swap(width, other.width);
        std::swap(height, other.height);
        std::swap(field, other.field);
        std::swap(entrance, other.entrance);
        std::swap(exit, other.exit);

        other.width = 0;
        other.height = 0;
        other.field = nullptr;
        other.entrance = {0, 0};
        other.exit = {0, 0};
    }
    return *this;
}

GameField::~GameField()
{
    if (field != nullptr)
    {
        for (int i = 0; i < height; ++i)
            delete[] field[i];
        delete[] field;
    }
}

bool GameField::valid(int x, int y)
{
    if (x < 0 || y < 0 || x >= width || y >= height)
        return false;
    return true;
}

Cell &GameField::getCell(int x, int y)
{
    if (!valid(x, y))
        throw std::out_of_range("Invalid cell coordinates");
    return field[y][x];
}

void GameField::setEntrance(int x, int y)
{
    if (!valid(x, y))
        throw std::out_of_range("Invalid entrance coordinates");
    entrance = std::make_pair(x, y);
}

void GameField::setExit(int x, int y)
{
    if (!valid(x, y))
        throw std::out_of_range("Invalid exit coordinates");
    exit = std::make_pair(x, y);
}

std::pair<int, int> GameField::getEntrance()
{
    return entrance;
}

std::pair<int, int> GameField::getExit()
{
    return exit;
}