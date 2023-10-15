#ifndef FIELD_H
#define FIELD_H
#include "Cell.h"
#include <utility>
#include <stdexcept>
#include <algorithm>

#define MAX_HEIGHT 100
#define MAX_WIDTH 200
#define MIN_HEIGHT 30
#define MIN_WIDTH 60

class GameField
{
private:
    int width, height;
    Cell **field;
    std::pair<int, int> entrance;
    std::pair<int, int> exit;

public:
    GameField(int width = MIN_WIDTH, int height = MIN_HEIGHT, int entranceX = 0, int entranceY = 0, int exitX = MIN_WIDTH - 1, int exitY = MIN_HEIGHT - 1);

    void normalization(int &width, int &height);

    Cell **fieldAlloc(int x, int y);

    GameField(const GameField &other);

    GameField(GameField &&other) noexcept;

    GameField &operator=(const GameField &other);

    GameField &operator=(GameField &&other) noexcept;

    ~GameField();

    bool valid(int x, int y);

    Cell &getCell(int x, int y);

    void setEntrance(int x, int y);

    void setExit(int x, int y);

    std::pair<int, int> getEntrance();

    std::pair<int, int> getExit();
};

#endif