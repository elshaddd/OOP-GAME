#include <iostream>
#include "Player/Player.h"
#include "Field/Field.h"
#include "Control/PlayerController.h"
#include "Generators/FieldGenerator.h"
#include "Util/DisplayAndLeveling.h"
#include "Game/Game.h"
#include "Input/InputSource/ConsoleInputSource/ConsoleInputSource.h"
#include <unistd.h>

int main()
{
    InputSource *inputSource = new ConsoleInputSource;
    Game game(inputSource);
    game.process();
}