cmake_minimum_required(VERSION 3.8)
project(hexgame)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Graph.cpp Graph.h HexBoard.cpp HexBoard.h DisjointSet.cpp DisjointSet.h Hexagon.cpp Hexagon.h Point.cpp Point.h Line.cpp Line.h HexGraph.cpp HexGraph.h Game.cpp Game.h InputHandler.cpp InputHandler.h Geometry.cpp Geometry.h commun.h)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
#PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} #[[${SDL2IMAGE_INCLUDE_DIRS}]])
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})