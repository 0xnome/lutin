cmake_minimum_required(VERSION 3.3)
project(lutin)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -ggdb -std=c++11")

file(GLOB_RECURSE SOURCE_FILES src/*)

add_executable(lutin ${SOURCE_FILES} src/etats/Etat.cpp src/etats/Etat.h)