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

GameField::GameField(int width, int height, std::pair<int, int> entrance, std::pair<int, int> exit)
{
    normalization(width, height);
    this->width = width;
    this->height = height;
    field = fieldAlloc(width, height);
    if (valid(entrance))
        this->entrance = entrance;
    if (valid(exit))
        this->exit = exit;
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

GameField::GameField(GameField &&other) noexcept : width(0), height(0), entrance({0, 0}), exit({0, 0}), field(nullptr)
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

bool GameField::valid(std::pair<int, int> coords)
{
    if (coords.first < 0 || coords.second < 0 || coords.first >= width || coords.second >= height)
        return false;
    return true;
}

Cell &GameField::getCell(std::pair<int, int> coords)
{
    if (!valid(coords))
        throw std::out_of_range("Invalid cell coordinates");
    return field[coords.second][coords.first];
}

std::pair<int, int> GameField::getCoords(const Cell &cell)
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            if (&field[i][j] == &cell)
            {
                return {j, i};
            }
        }
    }
    throw std::invalid_argument("Cell does not exist in this field");
}

int GameField::getWidth()
{
    return width;
}

int GameField::getHeight()
{
    return height;
}

std::pair<int, int> GameField::getEntrance()
{
    return entrance;
}

std::pair<int, int> GameField::getExit()
{
    return exit;
}

void GameField::setEntrance(std::pair<int, int> coords)
{
    if (!valid(coords))
        throw std::out_of_range("Invalid entrance coordinates");
    entrance = coords;
}

void GameField::setExit(std::pair<int, int> coords)
{
    if (!valid(coords))
        throw std::out_of_range("Invalid exit coordinates");
    exit = coords;
}

void GameField::printMaze()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (std::make_pair(j, i) == getEntrance())
            {
                std::cout << "]" << ' ';
            }
            else if (std::make_pair(j, i) == getExit())
            {
                std::cout << "[" << ' ';
            }
            else if (field[i][j].isPassable())
            {
                std::cout << " " << ' ';
            }
            else
            {
                std::cout << "*" << ' ';
            }
        }
        std::cout << "\n";
    }
}