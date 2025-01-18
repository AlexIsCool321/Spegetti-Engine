cmake_minimum_required(VERSION 3.10)

project(Spegetti_Project_Launcher)

set(EXE_NAME "Launcher")

set(Spegetti_Project_Launcher_Sources
	"Sources/NoClip.cpp"
	"Headers/NoClip.h"

	"Sources/Spegetti_Project_Launcher.cpp"
	"Headers/Spegetti_Project_Launcher.h"
)

add_executable(${EXE_NAME} ${Spegetti_Project_Launcher_Sources})

set_target_properties(${EXE_NAME} PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/../game"
	RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/../game"
)

add_dependencies(${EXE_NAME} Spegetti_Renderer)
add_dependencies(${EXE_NAME} Spegetti_Console)
add_dependencies(${EXE_NAME} Spegetti_Logic)
add_dependencies(${EXE_NAME} Spegetti_Files)

link_directories("${CMAKE_SOURCE_DIR}/../game/bin")

target_link_libraries(${EXE_NAME} PRIVATE Spegetti_Renderer)
target_link_libraries(${EXE_NAME} PRIVATE Spegetti_Console)
target_link_libraries(${EXE_NAME} PRIVATE Spegetti_Logic)
target_link_libraries(${EXE_NAME} PRIVATE Spegetti_Files)
