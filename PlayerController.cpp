#include "PlayerController.h"
#include "Player.h"

PlayerController::PlayerController(Player &player, GameField &gameField) : playerRef(player), gameFieldRef(gameField), coordinates(gameField.getEntrance()){}

void PlayerController::movePlayer(Direction direction)
{
    std::pair<int,int> temp = {coordinates.first, coordinates.second};
    switch (direction)
    {
    case UP:
        temp.second -=1;
        break;
    case DOWN:
        temp.second +=1;
        break;
    case RIGHT:
        temp.first +=1;
        break;
    case LEFT:
        temp.first -=1;
        break;
    default:
        break;
    }
    if(gameFieldRef.valid(temp.first,temp.second) && gameFieldRef.getCell(temp.first,temp.second).isPassable()){
        coordinates = temp;
    }
}

void PlayerController::modifyHealth(int value)
{
    int currentHealth = playerRef.getHealth();
    playerRef.setHealth(currentHealth + value);
}

void PlayerController::modifyScore(int points)
{
    int currentScore = playerRef.getScore();
    playerRef.setScore(currentScore + points);
}

void PlayerController::modifyDamage(int value)
{
    int currentDamage = playerRef.getDamage();
    playerRef.setDamage(currentDamage + value);
}

std::pair<int,int> PlayerController::getCoordinates(){
    return coordinates;
}