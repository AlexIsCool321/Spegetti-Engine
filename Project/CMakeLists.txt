cmake_minimum_required (VERSION 3.1)

include_directories(${PROJECT_NAME} PUBLIC "/")

project(Project)

set(Sources
"Sources/Project.cpp"
"Headers/Project.h"
)

add_executable(${PROJECT_NAME} ${Sources})

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/OUT/game"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/OUT/game"
)

link_directories("${CMAKE_CURRENT_SOURCE_DIR}/bin")

target_link_libraries(${PROJECT_NAME} "Spegetti")
