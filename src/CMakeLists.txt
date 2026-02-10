cmake_minimum_required(VERSION 3.10)
project("Spegetti Engine")

set(LANGUAGE C_STANDARD)
set(USE_FOLDERS ON)

add_subdirectory("Third Party")

add_subdirectory("Engine")
add_subdirectory("Plugins")
add_subdirectory("Launcher")