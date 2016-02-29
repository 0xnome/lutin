cmake_minimum_required(VERSION 2.8)
project(lutin)

include_directories(src/symboles)
include_directories(src/etats)
include_directories(src/automate)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -ggdb -std=c++0x")

file(GLOB_RECURSE SOURCE_FILES src/**)

add_executable(lutin ${SOURCE_FILES})
