cmake_minimum_required(VERSION 2.8)
project(main)

add_executable(main main.cpp)

include_directories(game .)
include_directories(map .)
include_directories(monster .)
include_directories(monster_factory .)
include_directories(player .)

add_subdirectory(game)
add_subdirectory(map)
add_subdirectory(monster)
add_subdirectory(monster_factory)
add_subdirectory(player)

target_link_libraries(main game)
target_link_libraries(main map)
target_link_libraries(main monster)
target_link_libraries(main monster_factory)
target_link_libraries(main player)