cmake_minimum_required(VERSION 2.8)
#project name
set(project_name lutin)
project(${project_name})

FIND_PACKAGE(Boost COMPONENTS program_options regex REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})

include_directories(lib)
include_directories(src/symboles)
include_directories(src/etats)
include_directories(src/automate)
include_directories(src/lexeur)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

if (WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -ggdb -std=c++0x -L "C:/Program Files/Boost/boost_1_55_0/stage/lib" -lboost_program_options -lboost_regex")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -ggdb -std=c++0x -lboost_program_options -lboost_regex")
endif ()


file(GLOB_RECURSE source_files "src/*.cpp")
file(GLOB_RECURSE header_files "src/*.h")
file(GLOB_RECURSE header_files "lib/*.h")


add_executable(${project_name} ${header_files} ${source_files})
TARGET_LINK_LIBRARIES(${project_name} ${Boost_LIBRARIES})
