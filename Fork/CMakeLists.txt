cmake_minimum_required (VERSION 3.1)

include_directories(${PROJECT_NAME} PUBLIC "/")

project(Fork)

set(Sources

"Sources/Fork.cpp"
"Headers/Fork.h"

)

add_executable(${PROJECT_NAME} ${Sources})

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/OUT/game/bin"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/OUT/game/bin"
)

link_directories("${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(${PROJECT_NAME} "Spegetti")
