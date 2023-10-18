#include "FieldGenerator.h"

FieldGenerator::FieldGenerator(GameField &gameField) : gameFieldRef(gameField) {}

// void FieldGenerator::addNeighbour(Cell *c, int x, int y)
// {
//     if (x > 0 && y > 0 && x < gameFieldRef.getWidth() - 1 && y < gameFieldRef.getHeight() - 1)
//     {
//         c->addNeighbour(&gameFieldRef.getCell({x, y}));
//     }
// }

void FieldGenerator::removeWall(Cell *a, Cell *b)
{
    std::pair<int, int> aCoords = gameFieldRef.getCoords(*a);
    std::pair<int, int> bCoords = gameFieldRef.getCoords(*b);
    int xDiff = aCoords.first - bCoords.first;
    int yDiff = aCoords.second - bCoords.second;

    if (xDiff == 2 || xDiff == -2)
    {
        gameFieldRef.field[aCoords.second][aCoords.first - (xDiff / 2)].setPassability(true);
    }
    if (yDiff == 2 || yDiff == -2)
    {
        gameFieldRef.field[aCoords.second - (yDiff / 2)][aCoords.first].setPassability(true);
    }
}

void FieldGenerator::generateMaze()
{
    populateNeighbours();
    processMazeCells();
}

void FieldGenerator::populateNeighbours()
{
    for (int y = 0; y < gameFieldRef.getHeight(); y++)
    {
        for (int x = 0; x < gameFieldRef.getWidth(); x++)
        {
            Cell &currentCell = gameFieldRef.getCell({x, y});
            std::vector<Cell *> neighbours = getNeighbours(currentCell);
            // currentCell.addNeighbour(neighbours);
        }
    }
}

// void FieldGenerator::populateNeighbours()
// {
//     for (int y = 0; y < gameFieldRef.getHeight(); y++)
//     {
//         for (int x = 0; x < gameFieldRef.getWidth(); x++)
//         {
//             addNeighbour(&gameFieldRef.field[y][x], x - 2, y);
//             addNeighbour(&gameFieldRef.field[y][x], x, y - 2);
//             addNeighbour(&gameFieldRef.field[y][x], x + 2, y);
//             addNeighbour(&gameFieldRef.field[y][x], x, y + 2);
//         }
//     }
// }
std::vector<Cell *> FieldGenerator::getNeighbours(Cell &cell)
{
    std::vector<Cell *> neighbours;
    std::pair<int, int> cellCoords = gameFieldRef.getCoords(cell);
    int x = cellCoords.first;
    int y = cellCoords.second;

    // Добавьте соседей в зависимости от вашей логики
    if (x - 2 >= 0)
        neighbours.push_back(&gameFieldRef.getCell({x - 2, y}));
    if (x + 2 < gameFieldRef.getWidth())
        neighbours.push_back(&gameFieldRef.getCell({x + 2, y}));
    if (y - 2 >= 0)
        neighbours.push_back(&gameFieldRef.getCell({x, y - 2}));
    if (y + 2 < gameFieldRef.getHeight())
        neighbours.push_back(&gameFieldRef.getCell({x, y + 2}));

    return neighbours;
}

void FieldGenerator::processMazeCells()
{
    Cell *start = &gameFieldRef.getCell({1, 1});
    cellStack.push(start);

    start->setPassability(true);
    std::random_device rd;
    std::mt19937 gen(rd());
    while (!cellStack.empty())
    {
        Cell *current = cellStack.top();
        cellStack.pop();
        std::vector<Cell *> unvisitedNeighbours;
        // std::pair<int, int> currentCoords = current->getCoords();

        // Получите соседей текущей клетки с учетом изменений
        std::vector<Cell *> neighbours = getNeighbours(*current);

        for (auto neighbour : neighbours)
        {
            if (!neighbour->isPassable())
            {
                unvisitedNeighbours.push_back(neighbour);
            }
        }
        if (!unvisitedNeighbours.empty())
        {
            cellStack.push(current);
            std::uniform_int_distribution<> distr(0, unvisitedNeighbours.size() - 1);
            int randomIndex = distr(gen);
            removeWall(current, unvisitedNeighbours[randomIndex]);
            unvisitedNeighbours[randomIndex]->setPassability(true);
            cellStack.push(unvisitedNeighbours[randomIndex]);
        }
    }
}


// void FieldGenerator::processMazeCells()
// {
//     Cell *start = &gameFieldRef.field[1][1];
//     cellStack.push(start);

//     start->setPassability(true);
//     std::random_device rd;
//     std::mt19937 gen(rd());
//     while (!cellStack.empty())
//     {
//         Cell *current = cellStack.top();
//         cellStack.pop();
//         std::vector<Cell *> unvisitedNeighbours;
//         for (auto neighbour : current->neighbours)
//         {
//             if (!neighbour->isPassable())
//             {
//                 unvisitedNeighbours.push_back(neighbour);
//             }
//         }
//         if (!unvisitedNeighbours.empty())
//         {
//             cellStack.push(current);
//             std::uniform_int_distribution<> distr(0, unvisitedNeighbours.size() - 1);
//             int randomIndex = distr(gen);
//             removeWall(current, unvisitedNeighbours[randomIndex]);
//             unvisitedNeighbours[randomIndex]->setPassability(true);
//             cellStack.push(unvisitedNeighbours[randomIndex]);
//         }
//     }
// }

FieldGenerator::~FieldGenerator()
{
    for (int i = 0; !cellStack.empty(); i++)
    {
        delete cellStack.top();
        cellStack.pop();
    }
};