cmake_minimum_required(VERSION 3.0)
project(test)

find_package(sqlite3 REQUIRED)
#find_package(SDL2 REQUIRED)

find_path(SDL2_INCLUDE_DIR SDL2/SDL.h)
find_library(SDL2_LIBRARY SDL2)
find_library(SDL2_MAIN SDL2main)

add_executable(main main.cpp)
target_include_directories(main PUBLIC ${SDL2_INCLUDE_DIR})
target_link_libraries(main PRIVATE ${SDL2_LIBRARY} ${SDL2_MAIN})