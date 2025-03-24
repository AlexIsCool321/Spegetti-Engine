cmake_minimum_required(VERSION 3.10)

project(Launcher)

set(Launcher_Sources

	"Sources/Launcher.cpp"
	"Headers/Launcher.h"
)

add_executable(${PROJECT_NAME} WIN32 ${Launcher_Sources})

#Third Part
add_dependencies(${PROJECT_NAME} "GLAD")
add_dependencies(${PROJECT_NAME} "IMGUI")

target_link_libraries(${PROJECT_NAME} PRIVATE "IMGUI")

# Engine
add_dependencies(${PROJECT_NAME} "Spegetti_Console")
add_dependencies(${PROJECT_NAME} "Spegetti_Entity_System")
add_dependencies(${PROJECT_NAME} "Spegetti_Files")
add_dependencies(${PROJECT_NAME} "Spegetti_Logic")
add_dependencies(${PROJECT_NAME} "Spegetti_Map_System")
add_dependencies(${PROJECT_NAME} "Spegetti_Memory")
add_dependencies(${PROJECT_NAME} "Spegetti_Renderer")

target_link_libraries(${PROJECT_NAME} PRIVATE "Spegetti_Renderer")
target_link_libraries(${PROJECT_NAME} PRIVATE "Spegetti_Logic")
target_link_libraries(${PROJECT_NAME} PRIVATE "Spegetti_Console")

# Tools
add_dependencies(${PROJECT_NAME} "Engine")
add_dependencies(${PROJECT_NAME} "UV_Viewer")
#add_dependencies(${PROJECT_NAME} "Fork")
add_dependencies(${PROJECT_NAME} "Material_Editor")

set_target_properties(${PROJECT_NAME} PROPERTIES
	FOLDER "Engine"

	RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/../game"
	RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/../game"
	VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/../game"
)