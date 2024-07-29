cmake_minimum_required (VERSION 3.10)

project("Spegetti_Engine")

set(Sources

"Engine/Spegetti Engine.h"
"Project/Sources/main.cpp"

)

add_executable(${PROJECT_NAME} ${Sources})

include_directories(${PROJECT_NAME} "/")