cmake_minimum_required(VERSION 3.10)

project(Launcher)

set(Launcher_Sources

	"Sources/Launcher.cpp"
	"Headers/Launcher.h"
)

add_executable(${PROJECT_NAME} ${Launcher_Sources})

add_dependencies(${PROJECT_NAME} Spegetti_Console)
add_dependencies(${PROJECT_NAME} Spegetti_Entity_System)
add_dependencies(${PROJECT_NAME} Spegetti_Files)
add_dependencies(${PROJECT_NAME} Spegetti_Logic)
add_dependencies(${PROJECT_NAME} Spegetti_Map_System)
add_dependencies(${PROJECT_NAME} Spegetti_Memory)
add_dependencies(${PROJECT_NAME} Spegetti_Renderer)

add_dependencies(${PROJECT_NAME} Engine)
add_dependencies(${PROJECT_NAME} UV_Viewer)

set_target_properties(${PROJECT_NAME} PROPERTIES
	FOLDER "Engine"

	RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/../game"
	RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/../game"
	VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/../game"
)