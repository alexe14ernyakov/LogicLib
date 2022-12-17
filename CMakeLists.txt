cmake_minimum_required(VERSION 3.23)
project(EA)

set(CMAKE_CXX_STANDARD 20)

add_executable(EA main.cpp game_field.h tile.h building.h enemy.h castle.h game_field.cpp config.h castle.cpp tile.cpp light_infantry.cpp light_infantry.h aviation.cpp aviation.h)
