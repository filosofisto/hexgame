cmake_minimum_required(VERSION 3.8)
project(hexgame)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Graph.cpp Graph.h HexBoard.cpp HexBoard.h)
add_executable(hexgame ${SOURCE_FILES})