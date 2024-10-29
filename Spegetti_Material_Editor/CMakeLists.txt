cmake_minimum_required (VERSION 3.5)

include_directories(${PROJECT_NAME} PUBLIC "/")
include_directories(${PROJECT_NAME} PUBLIC "/Headers")

project(Spegetti_Material_Editor)

set(Spegetti_Material_Editor_Sources
"Sources/Spegetti_Material_Editor.cpp"
"Headers/Spegetti_Material_Editor.h"
)
add_library(${PROJECT_NAME} ${Spegetti_Material_Editor_Sources})

set_target_properties(${PROJECT_NAME} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/OUT/game/bin"
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/OUT/game/bin"
)

link_directories("${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

target_link_libraries(${PROJECT_NAME} "Spegetti")