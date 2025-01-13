cmake_minimum_required(VERSION 3.10)

project(Spegetti_Renderer)

include_directories(${PROJECT_NAME} PUBLIC "/")

set(Spegetti_Renderer_Sources
"Sources/glad.c"
	
	"Sources/Window.cpp"
	"Sources/Camera.cpp"

	"Sources/Shader.cpp"
	"Sources/Material.cpp"

	"Sources/Vertex.cpp"
	"Sources/Mesh.cpp"

	"Headers/FreeCam.h"
	"Sources/FreeCam.cpp"
	
	"Sources/Spegetti_Renderer.cpp"
	"Headers/Spegetti_Renderer.h"
)

add_library(${PROJECT_NAME} ${Spegetti_Renderer_Sources})

if(32_BIT)
	target_link_libraries(${PROJECT_NAME} PRIVATE "GLFW/x86/glfw3")
else()
	target_link_libraries(${PROJECT_NAME} PRIVATE "GLFW/x64/glfw3")
endif()

link_directories("${CMAKE_SOURCE_DIR}/../game/bin")

target_link_libraries(${PROJECT_NAME} PRIVATE Spegetti_Files)

set_target_properties(${PROJECT_NAME} PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/../game/bin"
	ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/../game/bin"
)
