cmake_minimum_required(VERSION 3.10)
project("Spegetti Engine")

set(LANGUAGE C_STANDARD)
set(USE_FOLDERS ON)


set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)

set(CMAKE_INSTALL_RPATH "$ORIGIN/bin;$ORIGIN/../bin")
set(CMAKE_BUILD_WITH_INSTALL_RPATH ON)   


add_subdirectory("Third Party")

add_subdirectory("Engine")
add_subdirectory("Plugins")