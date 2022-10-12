cmake_minimum_required(VERSION 3.20.0)

project(Game_PetProject C CXX)

set(SOURCES
    ./src/main.cpp
)

set(CMAKE_DEBUG_POSTFIX -d)
set(BUILD_SHARED_LIBS OFF)

add_executable(${PROJECT_NAME} ${SOURCES})

add_subdirectory(./ext/SFML)

target_include_directories(${PROJECT_NAME} 
    PUBLIC ./ext/SFML/include
)

target_link_directories(${PROJECT_NAME}
    PRIVATE ./ext/SFML/src
)

target_link_libraries(${PROJECT_NAME} sfml-graphics)