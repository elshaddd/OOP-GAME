cmake_minimum_required(VERSION 3.5.0)
project(game)

set(CMAKE_CXX_STANDARD 17)
set(GCC_COVERAGE_COMPILE_FLAGS "-DLIN")

file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "src/*.h")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
add_executable(game main.cpp ${SOURCES} ${HEADERS})

add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})

set_target_properties(game PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})