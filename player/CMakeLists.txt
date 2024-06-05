cmake_minimum_required(VERSION 2.8)
project(player)
set(SOURCE_LIB player.cpp)
add_library(player STATIC ${SOURCE_LIB})
