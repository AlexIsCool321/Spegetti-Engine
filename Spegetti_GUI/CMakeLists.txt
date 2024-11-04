cmake_minimum_required (VERSION 3.5)

project(Spegetti_GUI)

include_directories(${PROJECT_NAME} PUBLIC "/")
include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/Spegetti_GUI/Headers")

set(Spegetti_GUI_Sources

    "Sources/Spegetti_GUI.cpp"
    "Headers/Spegetti_GUI.h"

)

add_library(${PROJECT_NAME} ${Spegetti_GUI_Sources})

message("==============================================================================================================")
message("${CMAKE_SOURCE_DIR}/Spegetti_GUI/Headers")
message("==============================================================================================================")

set_target_properties(${PROJECT_NAME} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/OUT/game/bin"
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/OUT/game/bin"
)

link_directories("${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

target_link_libraries(${PROJECT_NAME} "Spegetti")