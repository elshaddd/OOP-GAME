/**
 * The above code is a C++ implementation of a maze generator using a depth-first search algorithm.
 */
#include "FieldGenerator.h"

/**
 * The FieldGenerator class constructor initializes a reference to a GameField object.
 *
 * @param gameField The gameField parameter is a reference to an object of type GameField.
 */
FieldGenerator::FieldGenerator(GameField &gameField) : gameFieldRef(gameField) {}

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
 * The function "generateField" generates a maze by populating the neighbours of each cell and
 * processing the maze cells.
 */
void FieldGenerator::generateField()
{
    populateNeighbours();
    processMazeCells();
    fillByEvents();
}

/**
 * The function `populateNeighbours` iterates through each cell in a game field and retrieves its
 * neighboring cells.
 */
void FieldGenerator::populateNeighbours()
{
    for (int y = 0; y < gameFieldRef.getHeight(); y++)
    {
        for (int x = 0; x < gameFieldRef.getWidth(); x++)
        {
            Cell &currentCell = gameFieldRef.getCell({x, y});
            std::vector<Cell *> neighbours = getNeighbours(currentCell);
        }
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
    std::random_device rd;
    std::mt19937 gen(rd());
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

/**
 * The function "fillByEvents" performs a depth-first search to visit all passable cells in the maze.
 *
 * @param start The starting cell for the traversal.
 */
void FieldGenerator::fillByEvents()
{
    Cell *start = &gameFieldRef.getCell({START_CELL_X, START_CELL_Y});
    std::stack<Cell *> cellStack;
    cellStack.push(start);

    // Create a set to track visited cells
    std::set<Cell *> visitedCells;
    int passableCellCount = 0;
    while (!cellStack.empty())
    {
        Cell *current = cellStack.top();
        cellStack.pop();

        visitedCells.insert(current); // Mark the cell as visited

        std::vector<Cell *> neighbours = getNeighbours(*current);
        for (auto neighbour : neighbours)
        {
            if (neighbour->isPassable() && visitedCells.find(neighbour) == visitedCells.end())
            {
                passableCellCount++;
                if (passableCellCount % 10 == 0)
                {
                    // Set the event on every eighth passable cell
                    current->setEvent(getRandomEvent());
                }
                cellStack.push(neighbour);
            }
        }
    }
}

/**
 * The getRandomEvent function generates a random event from a predefined list of events and returns a
 * pointer to the selected event.
 *
 * @return a pointer to a randomly selected Event object.
 */
Event *FieldGenerator::getRandomEvent()
{
    std::mt19937 rng1(static_cast<unsigned int>(std::time(0)));
    std::uniform_int_distribution<int> distribution1(1, gameFieldRef.getHeight());
    int randomY = distribution1(rng1);
    // std::mt19937 rng2(static_cast<unsigned int>(std::time(0)));
    std::uniform_int_distribution<int> distribution2(1, gameFieldRef.getWidth());
    int randomX = distribution2(rng1);

    // Создайте массив указателей на события
    Event *events[] = {
        new NegativeDamageEvent(),
        new NegativeHealthEvent(),
        new NegativeScoreEvent(),
        new NeutralCoordsEvent(std::make_pair(randomX, randomY)),
        new PositiveDamageEvent(),
        new PositiveHealthEvent(),
        new PositiveScoreEvent()};

    // Получите количество событий
    int numEvents = sizeof(events) / sizeof(events[0]);

    // Инициализируйте генератор случайных чисел
    // std::mt19937 rng(static_cast<unsigned int>(std::time(0)));
    std::uniform_int_distribution<int> distribution(0, numEvents - 1);

    // Генерируйте случайное число для выбора события
    int randomIndex = distribution(rng1);

    // Верните указатель на случайное событие
    return events[randomIndex]->clone();
}