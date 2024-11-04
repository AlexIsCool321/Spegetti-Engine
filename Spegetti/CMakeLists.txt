cmake_minimum_required (VERSION 3.5)

project(Spegetti)

include_directories(${PROJECT_NAME} PUBLIC "/")
include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/Spegetti/Headers")

set(Spegetti_Sources

    "Sources/Spegetti.cpp"
    "Headers/Spegetti.h"

    "Sources/Glad/glad.c"

) 

add_library(${PROJECT_NAME} ${Spegetti_Sources})

set_target_properties(${PROJECT_NAME} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/OUT/game/bin"
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/OUT/game/bin"
)

link_directories("${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

target_link_libraries(${PROJECT_NAME} "Libraries/glfw3")