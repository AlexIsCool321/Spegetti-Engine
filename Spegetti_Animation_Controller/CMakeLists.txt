cmake_minimum_required (VERSION 3.5)

include_directories(${PROJECT_NAME} PUBLIC "/")

project(Spegetti_Animation_Controller)

set(Spegetti_Animation_Controller_Sources

    "Sources/Spegetti_Animation_Controller.cpp"
    "Headers/Spegetti_Animation_Controller.h"

)

add_executable(${PROJECT_NAME} ${Spegetti_Animation_Controller_Sources})

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/OUT/game/bin"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/OUT/game/bin"
)

link_directories("${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

target_link_libraries(${PROJECT_NAME} "Spegetti")
