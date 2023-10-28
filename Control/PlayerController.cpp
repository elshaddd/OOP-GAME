#include "PlayerController.h"

PlayerController::PlayerController(Player &player, GameField &gameField) : playerRef(player), gameFieldRef(gameField), coordinates(gameField.getEntrance()) {}

void PlayerController::movePlayer(Direction direction)
{
    std::pair<int, int> temp = {coordinates.first, coordinates.second};
    std::pair<int, int> temp1 = {coordinates.first, coordinates.second};
    switch (direction)
    {
    case UP:
        temp.second -= 1;
        break;
    case DOWN:
        temp.second += 1;
        break;
    case RIGHT:
        temp.first += 1;
        break;
    case LEFT:
        temp.first -= 1;
        break;
    default:
        break;
    }
    if (gameFieldRef.valid(temp) && gameFieldRef.getCell(temp).isPassable())
    {
        coordinates = temp;
        Event *event = gameFieldRef.getCell(coordinates).getEvent();
        if (event != nullptr)
        {
            event->OnPlayerStep(*this);
            gameFieldRef.getCell(temp).removeEvent();
        }
    }
}

void PlayerController::modifyHealth(int value)
{
    int currentHealth = playerRef.getHealth();
    playerRef.setHealth(currentHealth + value);
    if (playerRef.getHealth() == 0)
    {
        std::cout << "GAME OVER\n";
        std::exit(0);
    }
}

void PlayerController::modifyScore(int points)
{
    int currentScore = playerRef.getScore();
    playerRef.setScore(currentScore + points);
}

// void PlayerController::modifyDamage(int value)
// {
//     int currentDamage = playerRef.getDamage();
//     playerRef.setDamage(currentDamage + value);
// }

void PlayerController::setCoordinates(std::pair<int, int> coords)
{
    if (gameFieldRef.valid(coords))
    {
        if (gameFieldRef.getCell(coords).isPassable())
            coordinates = coords;
        if (gameFieldRef.getCell(coords).getEvent() != nullptr)
            gameFieldRef.getCell(coords).getEvent()->OnPlayerStep(*this);
            gameFieldRef.getCell(coords).removeEvent();
    }
}

std::pair<int, int> PlayerController::getCoordinates()
{
    return coordinates;
}

// PlayerController::PlayerController(const PlayerController &other)
//     : playerRef(other.playerRef), gameFieldRef(other.gameFieldRef), coordinates(other.coordinates) {}

// PlayerController &PlayerController::operator=(const PlayerController &other)
// {
//     if (this != &other)
//     {
//         playerRef = other.playerRef;
//         gameFieldRef = other.gameFieldRef;
//         coordinates = other.coordinates;
//     }
//     return *this;
// }