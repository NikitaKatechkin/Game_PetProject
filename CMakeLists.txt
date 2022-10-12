cmake_minimum_required(VERSION 3.20.0)

project(Game_PetProject C CXX)

set(SOURCES
    ./src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})