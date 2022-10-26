cmake_minimum_required(VERSION 3.20.0)

project(Game_PetProject C CXX)

set(SOURCES
    ./src/main.cpp
    ./src/window/Window.cpp
    ./src/game/Game.cpp
    ./src/gameObjects/GameObject.cpp
    ./src/gameObjects/MovableObject.cpp
    ./src/player/Player.cpp
    ./src/map/Map.cpp
)

set(HEADERS
    ./src/window/Window.h
    ./src/game/Game.h
    ./src/DataTypes.h
    ./src/gameObjects/GameObject.h
    ./src/gameObjects/MovableObject.h
    ./src/gameObjects/HandlingObject.h
    ./src/player/Player.h
    ./src/map/Map.h
)

set(BUILD_SHARED_LIBS OFF)

add_subdirectory(./ext/SFML)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME} 
    PUBLIC ./ext/SFML/include
)

target_link_directories(${PROJECT_NAME}
    PRIVATE ./ext/SFML/src
)

target_link_libraries(${PROJECT_NAME} sfml-graphics)