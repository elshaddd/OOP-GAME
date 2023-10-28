/**
 * The above code is a C++ implementation of a maze generator using a depth-first search algorithm.
 */
#include "FieldGenerator.h"

/**
 * The FieldGenerator constructor initializes a random number generator using a random device and
 * assigns it to the gen member variable.
 *
 * @param gameField The gameField parameter is a reference to an object of type GameField.
 */
FieldGenerator::FieldGenerator(GameField &gameField) : gameFieldRef(gameField)
{
    std::random_device rd;
    gen = std::mt19937(rd());
}

/**
 * The function removes a wall between two cells in a game field.
 *
 * @param a Cell a is a pointer to a Cell object.
 * @param b b is a pointer to a Cell object.
 */
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

/**
 * The function "getNeighbours" returns a vector of pointers to the neighboring cells of a given cell
 * in a game field.
 *
 * @param cell A reference to a Cell object.
 *
 * @return a vector of pointers to Cell objects.
 */
std::vector<Cell *> FieldGenerator::getNeighbours(Cell &cell)
{
    std::vector<Cell *> neighbours;
    std::pair<int, int> cellCoords = gameFieldRef.getCoords(cell);
    int x = cellCoords.first;
    int y = cellCoords.second;

    if (x - NEIGHBOUR_OFFSET >= 0)
        neighbours.push_back(&gameFieldRef.getCell({x - NEIGHBOUR_OFFSET, y}));
    if (x + NEIGHBOUR_OFFSET < gameFieldRef.getWidth())
        neighbours.push_back(&gameFieldRef.getCell({x + NEIGHBOUR_OFFSET, y}));
    if (y - NEIGHBOUR_OFFSET >= 0)
        neighbours.push_back(&gameFieldRef.getCell({x, y - NEIGHBOUR_OFFSET}));
    if (y + NEIGHBOUR_OFFSET < gameFieldRef.getHeight())
        neighbours.push_back(&gameFieldRef.getCell({x, y + NEIGHBOUR_OFFSET}));

    return neighbours;
}

/**
 * The function "processMazeCells" generates a maze by randomly removing walls between cells.
 */
void FieldGenerator::processMazeCells()
{
    Cell *start = &gameFieldRef.getCell({START_CELL_X, START_CELL_Y});
    cellStack.push(start);
    start->setPassability(true);
    while (!cellStack.empty())
    {
        Cell *current = cellStack.top();
        cellStack.pop();
        std::vector<Cell *> unvisitedNeighbours;
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

/**
 * The getRandomEvent function generates a random event from a predefined list of events.
 *
 * @return a pointer to an Event object.
 */
Event *FieldGenerator::getRandomEvent()
{
    std::uniform_int_distribution<int> distributionY(START_CELL_X, gameFieldRef.getHeight() - 2);
    std::uniform_int_distribution<int> distributionX(START_CELL_Y, gameFieldRef.getWidth() - 2);

    Event *events[] = {
        new NeutralCoordsEvent({1, 1}),
        // new NegativeDamageEvent(),
        new NegativeHealthEvent(),
        new NegativeScoreEvent(),
        // new PositiveDamageEvent(),
        new PositiveHealthEvent(),
        new PositiveScoreEvent()};
    // std::vector<Event*> events;
    // events.push_back(new NeutralCoordsEvent({1, 1}));
    // // events.push_back(new NegativeDamageEvent());
    // events.push_back(new NegativeHealthEvent());
    // events.push_back(new NegativeScoreEvent());
    // // events.push_back(new PositiveDamageEvent());
    // events.push_back(new PositiveHealthEvent());
    // events.push_back(new PositiveScoreEvent());

    int numEvents = sizeof(events) / sizeof(events[0]);
    std::uniform_int_distribution<int> distribution(0, numEvents - 1);

    int randomIndex = distribution(gen);
    if (randomIndex == 0)
    {
        int randomX, randomY;
        do
        {
            randomY = distributionY(gen);
            randomX = distributionX(gen);
        } while (gameFieldRef.getCell({randomX, randomY}).isPassable() == false);
        delete events[0];
        events[0] = new NeutralCoordsEvent(std::make_pair(randomX, randomY));
    }
    for (int i = 0; i < numEvents; i++)
    {
        if (i != randomIndex)
            delete events[i];
    }
    return events[randomIndex]->clone();
}

/**
 * The function "fillByEvents" performs a depth-first search to visit all passable cells in the maze.
 *
 * @param start The starting cell for the traversal.
 */
void FieldGenerator::fillByEvents()
{
    Cell *start = &gameFieldRef.getCell({START_CELL_X, START_CELL_Y});
    cellStack.push(start);

    std::set<Cell *> visitedCells;
    int passableCellCount = 0;
    while (!cellStack.empty())
    {
        Cell *current = cellStack.top();
        cellStack.pop();

        visitedCells.insert(current);

        std::vector<Cell *> neighbours = getNeighbours(*current);
        for (auto neighbour : neighbours)
        {
            if (neighbour->isPassable() && visitedCells.find(neighbour) == visitedCells.end())
            {
                passableCellCount++;
                if (passableCellCount % EVENT_FREQ == 0)
                {
                    current->setEvent(getRandomEvent());
                }
                cellStack.push(neighbour);
            }
        }
    }
}

/**
 * The generateField function processes maze cells and fills them with events.
 */
void FieldGenerator::generateField()
{
    processMazeCells();
    fillByEvents();
}

/**
 * The destructor for the FieldGenerator class deletes all elements in the cellStack.
 */
FieldGenerator::~FieldGenerator()
{
    while (!cellStack.empty())
    {
        delete cellStack.top();
        cellStack.pop();
    }
}