cmake_minimum_required(VERSION 3.10)

project(Material_Editor)

set(Material_Editor_Sources

	"Sources/NoClip.cpp"
	"Headers/NoClip.h"

	"Sources/Material_Editor.cpp"
	"Headers/Material_Editor.h"
)

add_executable(${PROJECT_NAME} WIN32 ${Material_Editor_Sources})

target_link_libraries(${PROJECT_NAME} PRIVATE "IMGUI")

add_dependencies(${PROJECT_NAME} "Spegetti_Renderer")
add_dependencies(${PROJECT_NAME} "Spegetti_Console")
add_dependencies(${PROJECT_NAME} "Spegetti_Logic")
add_dependencies(${PROJECT_NAME} "Spegetti_Files")

link_directories("${CMAKE_SOURCE_DIR}/../build/shared")

target_link_libraries(${PROJECT_NAME} PRIVATE "Spegetti_Memory")
target_link_libraries(${PROJECT_NAME} PRIVATE "Spegetti_Renderer")
target_link_libraries(${PROJECT_NAME} PRIVATE "Spegetti_Console")
target_link_libraries(${PROJECT_NAME} PRIVATE "Spegetti_Logic")
target_link_libraries(${PROJECT_NAME} PRIVATE "Spegetti_Files")

set_target_properties(${PROJECT_NAME} PROPERTIES
	FOLDER "Tools"
	
	RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/../game/bin"
	RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/../game/bin"
)