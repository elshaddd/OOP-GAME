# # # g++ *.cpp .\Events\NegativeEvents\*.cpp .\Events\PositiveEvents\*.cpp .\Events\NeutralEvents\*.cpp .\Generators\*.cpp

# # # g++ *.cpp ./Events/NegativeEvents/*.cpp ./Events/PositiveEvents/*.cpp ./Events/NeutralEvents/*.cpp ./Generators/*.cpp && ./a.out

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

# # g++ Player/*.cpp Generators/*.cpp Field/*.cpp Events/NegativeEvents/*.cpp Events/PositiveEvents/*.cpp Events/NeutralEvents/*.cpp Control/*.cpp main.cpp -DLIN && ./a.out
# # g++ Player\*.cpp Generators\*.cpp Field\*.cpp Events\NegativeEvents\*.cpp Events\PositiveEvents\*.cpp Events\NeutralEvents\*.cpp Control\*.cpp main.cpp ; ./a

all: game
game:
	g++ Player/*.cpp Generators/*.cpp Field/*.cpp Events/NegativeEvents/*.cpp Events/PositiveEvents/*.cpp Events/NeutralEvents/*.cpp Control/*.cpp main.cpp -DLIN && ./a.out