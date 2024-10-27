cmake_minimum_required (VERSION 3.5)

include_directories(${PROJECT_NAME} PUBLIC "Spegetti/Headers")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/OUT/game/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/OUT/game/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/OUT/game/bin")

project(Project)

add_subdirectory("Project")

project(Fork)

add_subdirectory("Fork")

project(Entity_System)

add_subdirectory("Entity_System")

project(Spegetti)

add_subdirectory("Spegetti")