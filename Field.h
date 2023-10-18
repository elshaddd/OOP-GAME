#ifndef FIELD_H
#define FIELD_H
#include "Cell.h"
#include <utility>
#include <stdexcept>
#include <algorithm>
#include <iostream>

#define MAX_HEIGHT 100
#define MAX_WIDTH 200
#define MIN_HEIGHT 25
#define MIN_WIDTH 51

class GameField
{
private:
    int width, height;
    Cell **field;
    std::pair<int, int> entrance;
    std::pair<int, int> exit;

public:
    GameField(int width = MIN_WIDTH, int height = MIN_HEIGHT, std::pair<int, int> entrance = {1, 1}, std::pair<int, int> exit = {MIN_WIDTH - 2, MIN_HEIGHT - 2});

    void normalization(int &width, int &height);

    Cell **fieldAlloc(int x, int y);

    GameField(const GameField &other);

    GameField(GameField &&other) noexcept;

    GameField &operator=(const GameField &other);

    GameField &operator=(GameField &&other) noexcept;

    ~GameField();

    bool valid(std::pair<int, int> coords);

    Cell &getCell(std::pair<int, int> coords);

    std::pair<int, int> getCoords(const Cell &cell);

    int getWidth();

    int getHeight();

    std::pair<int, int> getEntrance();

    std::pair<int, int> getExit();

    void setEntrance(std::pair<int, int> coords);

    void setExit(std::pair<int, int> coords);

    void printMaze();

    friend class FieldGenerator;
};

#endif