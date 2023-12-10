#include <iostream>
#include "src/Player/Player.h"
#include "src/Field/Field.h"
#include "src/Control/PlayerController.h"
#include "src/Generators/FieldGenerator.h"
#include "src/Game/Game.h"
#include "src/Input/InputSource/ConsoleInputSource/ConsoleInputSource.h"
#include "src/Input/InputSource/FileInputSource/FileInputSource.h"
#include "src/GameClient/GameClient.h"
#include "src/Logging/Logger/ConsoleLogger/ConsoleLogger.h"
#include "src/Logging/Logger/FileLogger/FileLogger.h"
#include "src/Logging/Dispatcher/MessageDispatcher.h"
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