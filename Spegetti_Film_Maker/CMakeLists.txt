cmake_minimum_required (VERSION 3.5)

include_directories(${PROJECT_NAME} PUBLIC "/")

project(Spegetti_Film_Maker)

set(Sources

"Sources/Spegetti_Film_Maker.cpp"
"Headers/Spegetti_Film_Maker.h"

)

add_executable(${PROJECT_NAME} ${Sources})

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/OUT/game/bin"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/OUT/game/bin"
)

link_directories("${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

target_link_libraries(${PROJECT_NAME} "Spegetti")
