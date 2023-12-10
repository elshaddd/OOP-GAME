#ifndef FIELD_GENERATOR_H
#define FIELD_GENERATOR_H

#include "../Field/Field.h"
// #include "../Events/NegativeEvents/Damage.h"
#include "../Events/NegativeEvents/Health.h"
#include "../Events/NegativeEvents/Score.h"
// #include "../Events/PositiveEvents/Damage.h"
#include "../Events/PositiveEvents/Health.h"
#include "../Events/PositiveEvents/Score.h"
#include "../Events/NeutralEvents/Coords.h"
#include <iostream>
#include <stack>
#include <vector>
#include <set>
#include <cstdlib>
#include <ctime>
#include <random>
const int EVENT_FREQ = 15;
const int NEIGHBOUR_OFFSET = 2;
const int START_CELL_X = 1;
const int START_CELL_Y = 1;

class FieldGenerator
{
public:
    FieldGenerator(GameField &gameField);

    void generateField();

    ~FieldGenerator();

private:
    GameField &gameFieldRef;

    std::stack<Cell *> cellStack;

    std::vector<Cell *> getNeighbours(Cell &cell);

    void removeWall(Cell *a, Cell *b);

    void processMazeCells();

    void fillByEvents();

    Event *getRandomEvent();

    std::mt19937 gen;
};

#endif