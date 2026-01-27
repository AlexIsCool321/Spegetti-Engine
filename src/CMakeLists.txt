cmake_minimum_required(VERSION 3.27)
project("Spegetti Engine")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(USE_FOLDERS ON)

add_subdirectory("Third Party")
add_subdirectory("Engine")
add_subdirectory("Game")