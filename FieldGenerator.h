#ifndef FIELDGENERATOR_H
#define FIELDGENERATOR_H

#include "Field.h"
#include <iostream>
#include <stack>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <random>

class FieldGenerator
{
public:
    FieldGenerator(GameField &gameField);
    
    void generateMaze();

    void addNeighbour(Cell *c, int x, int y);

    void removeWall(Cell *a, Cell *b);

    void populateNeighbours();

    void processMazeCells();

    ~FieldGenerator();

private:
    GameField &gameFieldRef;

    std::stack<Cell *> cellStack;
};

#endif
