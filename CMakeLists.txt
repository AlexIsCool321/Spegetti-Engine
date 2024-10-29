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


project(Map_System)

add_subdirectory("Map_System")


project(Spegetti_Noodle)

add_subdirectory("Spegetti_Noodle")


project(Spegetti_Animation)

add_subdirectory("Spegetti_Animation")


project(Spegetti_Film_Maker)

add_subdirectory("Spegetti_Film_Maker")


project(Spegetti_Animation_Controller)

add_subdirectory("Spegetti_Animation_Controller")


project(Spegetti_Sauce)

add_subdirectory("Spegetti_Sauce")


project(Spegetti_Material_Editor)

add_subdirectory("Spegetti_Material_Editor")


project(Spegetti_Launcher)

add_subdirectory("Spegetti_Launcher")


project(Spegetti_GUI)

add_subdirectory("Spegetti_GUI")


project(Spegetti)

add_subdirectory("Spegetti")
