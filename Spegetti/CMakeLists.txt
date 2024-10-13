cmake_minimum_required (VERSION 3.1)

include_directories(${PROJECT_NAME} PUBLIC "/")

project(Spegetti)

set(Sources
"Sources/Spegetti.cpp"
"Headers/Spegetti.h"
)

add_library(${PROJECT_NAME} ${Sources})

set_target_properties(${PROJECT_NAME} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/OUT/game/bin"
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/OUT/game/bin"

)