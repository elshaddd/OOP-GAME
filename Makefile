# CC=g++
# CFLAGS= -std=c++20 -O2 -I./
# SOURCES=Player/*.cpp Field/*.cpp Control/*.cpp Generators/*.cpp Events/NegativeEvents/*.cpp Events/PositiveEvents/*.cpp Events/NeutralEvents/*.cpp  main.cpp
# OBJECTS=$(SOURCES:.cpp=.o)
# EXECUTABLE=game

# all: $(EXECUTABLE)
	
# $(EXECUTABLE): $(OBJECTS) 
# 	$(CC) $(CFLAGS) -o $@ $(OBJECTS)

# .cpp.o:
# 	$(CC) $(CFLAGS) -c $< -o $@

# g++ Player/*.cpp Generators/*.cpp Field/*.cpp Events/NegativeEvents/*.cpp Events/PositiveEvents/*.cpp Events/NeutralEvents/*.cpp Control/*.cpp main.cpp Events/Visitor/*.cpp -DLIN && ./a.out

#g++ Player\*.cpp Generators\*.cpp Field\*.cpp Events\NegativeEvents\*.cpp Events\PositiveEvents\*.cpp Events\NeutralEvents\*.cpp Control\*.cpp Events\Visitor\*.cpp Game\*.cpp Input\Commands\Exit\*.cpp Input\Commands\MoveDown\*.cpp Input\Commands\MoveUp\*.cpp Input\Commands\MoveLeft\*.cpp Input\Commands\MoveRight\*.cpp Input\InputHandler\*.cpp Input\InputSource\ConsoleInputSource\*.cpp Input\InputSource\FileInputSource\*.cpp Input\Commands\Quit\*.cpp *.cpp Input\Commands\Start\*.cpp Input\Commands\Select\*.cpp Input\Commands\SelectLevel\*.cpp Input\Commands\Restart\*.cpp Input\Commands\Menu\*.cpp GameClient\*.cpp Invoker\*.cpp ; ./a

#g++ Player/*.cpp Generators/*.cpp Field/*.cpp Events/NegativeEvents/*.cpp Events/PositiveEvents/*.cpp Events/NeutralEvents/*.cpp Control/*.cpp Events/Visitor/*.cpp Game/*.cpp Input/Commands/Exit/*.cpp Input/Commands/MoveDown/*.cpp Input/Commands/MoveUp/*.cpp Input/Commands/MoveLeft/*.cpp Input/Commands/MoveRight/*.cpp Input/InputHandler/*.cpp Input/InputSource/ConsoleInputSource/*.cpp Input/InputSource/FileInputSource/*.cpp Input/Commands/Quit/*.cpp *.cpp Input/Commands/Start/*.cpp Input/Commands/Select/*.cpp Input/Commands/SelectLevel/*.cpp Input/Commands/Restart/*.cpp Input/Commands/Menu/*.cpp GameClient/*.cpp Invoker/*.cpp -DLIN -o game && ./game
all: games
games:
	g++ Player/*.cpp Generators/*.cpp Field/*.cpp Events/NegativeEvents/*.cpp Events/PositiveEvents/*.cpp Events/NeutralEvents/*.cpp Control/*.cpp Events/Visitor/*.cpp Game/*.cpp Input/Commands/Exit/*.cpp Input/Commands/MoveDown/*.cpp Input/Commands/MoveUp/*.cpp Input/Commands/MoveLeft/*.cpp Input/Commands/MoveRight/*.cpp Input/InputHandler/*.cpp Input/InputSource/ConsoleInputSource/*.cpp Input/InputSource/FileInputSource/*.cpp Input/Commands/Quit/*.cpp *.cpp Input/Commands/Start/*.cpp Input/Commands/Select/*.cpp Input/Commands/SelectLevel/*.cpp Input/Commands/Restart/*.cpp Input/Commands/Menu/*.cpp GameClient/*.cpp Invoker/*.cpp -DLIN -o game && ./game