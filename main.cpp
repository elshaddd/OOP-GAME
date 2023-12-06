#include <iostream>
#include "Player/Player.h"
#include "Field/Field.h"
#include "Control/PlayerController.h"
#include "Generators/FieldGenerator.h"
#include "Util/DisplayAndLeveling.h"
#include "Game/Game.h"
#include "Input/InputSource/ConsoleInputSource/ConsoleInputSource.h"
#include "Input/InputSource/FileInputSource/FileInputSource.h"
#include "GameClient/GameClient.h"
#include "Logging/Logger/ConsoleLogger/ConsoleLogger.h"
#include "Logging/Logger/FileLogger/FileLogger.h"
#include "Logging/Dispatcher/MessageDispatcher.h"
#include <unistd.h>

int main()
{
    MessageDispatcher dispatcher;
    std::string output;
    std::cout << "Where do you want to output messages? (file, console, both, nowhere)" << std::endl;
    std::cin >> output;
    if (output == "file" || output == "both")
    {
        dispatcher.addObserver(new FileLogger("log.txt"));
    }
    if (output == "console" || output == "both")
    {
        dispatcher.addObserver(new ConsoleLogger());
    }
    if (output == "nowhere")
    {
        GameClient gameC;
        gameC.loop();
        return 0;
    }
    GameClient gameC(&dispatcher);
    gameC.loop();
}