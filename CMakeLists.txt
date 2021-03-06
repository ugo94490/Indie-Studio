cmake_minimum_required(VERSION 3.11)
set(NAME bomberman)
project(${NAME})
set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR})

if (UNIX)
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -isystem/usr/include/irrlicht/ -I/usr/X11R6/include -Wall -Wextra -Wshadow -L/usr/X11R6/lib64 -lGL -lXxf86vm -lXext -lX11 -lIrrlicht -g3 -lsfml-audio")
    include_directories(lib/irrlicht-1.8.4/include include)
    link_directories(${CMAKE_SOURCE_DIR}/lib/irrlicht-1.8.4/lib/Linux)
endif (UNIX)
if (WIN32)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Irrlicht_win/include)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include include)
    link_directories(${CMAKE_CURRENT_SOURCE_DIR}/Irrlicht_win)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.5.1/include)
    set(SFML_STATIC_LIBRARIES TRUE)
    set (CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/SFML-2.5.1/lib/cmake/SFML)
    set(SFML_DIR ${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.5.1/lib/cmake/SFML)
    find_package (SFML 2.5 COMPONENTS system audio REQUIRED)
    include_directories(${SFML_INCLUDE_DIR})
endif(WIN32)

set(SOURCE_FILES
    src/main.cpp
    src/Module/Core.cpp
    src/Module/Game.cpp
    src/Module/Menu.cpp
    src/Module/Settings.cpp
    src/Module/LeaderBoard.cpp
    src/Module/Credit.cpp
    src/Module/HowTo.cpp
    src/Module/Load.cpp
    src/Object/SolidWall.cpp
    src/Object/Ground.cpp
    src/Object/BreakableWall.cpp
    src/Object/Powerup.cpp
    src/Object/Explosion.cpp
    src/Object/Bomb.cpp
    src/Player/Player.cpp
    src/Map/Map.cpp
    src/Map/GeneratorMap.cpp
    src/Factory.cpp
    src/Sound/Sound.cpp)
add_executable(${NAME} ${SOURCE_FILES})

target_link_libraries(${NAME} sfml-system sfml-audio)