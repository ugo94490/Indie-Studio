cmake_minimum_required(VERSION 3.11)
set(NAME bomberman)
project(${NAME})
set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

if (UNIX)
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -isystem/usr/include/irrlicht/ -I/usr/X11R6/include -Wall -Wextra -Wshadow -L/usr/X11R6/lib64 -lGL -lXxf86vm -lXext -lX11 -lIrrlicht")
    include_directories(lib/irrlicht-1.8.4/include include)
    link_directories(${CMAKE_SOURCE_DIR}/lib/irrlicht-1.8.4/lib/Linux)
endif (UNIX)
if (WIN32)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Irrlicht_win/include)
    link_directories(${CMAKE_CURRENT_SOURCE_DIR}/Irrlicht_win)
endif(WIN32)

set(SOURCE_FILES
    src/main.cpp
    src/Map.cpp
    src/Core.cpp
    src/AObject.cpp
    src/APlayer.cpp
    src/Floor.cpp
    src/Game.cpp
    src/Menu.cpp
    src/Normal.cpp
    src/Obstacle.cpp
    src/Wall.cpp
    src/GeneratorMap.cpp)
add_executable(${NAME} ${SOURCE_FILES})