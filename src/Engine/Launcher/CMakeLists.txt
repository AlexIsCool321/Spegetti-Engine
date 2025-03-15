cmake_minimum_required(VERSION 3.10)

project(Launcher)

set(Launcher_Sources

	"Sources/NoClip.cpp"
	"Headers/NoClip.h"

	"Sources/Launcher.cpp"
	"Headers/Launcher.h"
)

add_executable(${PROJECT_NAME} ${Launcher_Sources})

set_target_properties(${PROJECT_NAME} PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/../game"
	RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/../game"
)

add_dependencies(${PROJECT_NAME} Spegetti_Renderer)
add_dependencies(${PROJECT_NAME} Spegetti_Console)
add_dependencies(${PROJECT_NAME} Spegetti_Logic)
add_dependencies(${PROJECT_NAME} Spegetti_Files)

link_directories("${CMAKE_SOURCE_DIR}/../build/shared")

target_link_libraries(${PROJECT_NAME} PRIVATE Spegetti_Memory)
target_link_libraries(${PROJECT_NAME} PRIVATE Spegetti_Renderer)
target_link_libraries(${PROJECT_NAME} PRIVATE Spegetti_Console)
target_link_libraries(${PROJECT_NAME} PRIVATE Spegetti_Logic)
target_link_libraries(${PROJECT_NAME} PRIVATE Spegetti_Files)
