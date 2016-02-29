cmake_minimum_required(VERSION 2.8)
#project name
set(project_name lutin)
project(${project_name})

include_directories(src/symboles)
include_directories(src/etats)
include_directories(src/automate)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -ggdb -std=c++0x")

file(GLOB_RECURSE source_files "src/*.cpp")
file(GLOB_RECURSE header_files "src/*.h")

add_executable(${project_name} ${header_files} ${source_files})
