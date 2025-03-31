cmake_minimum_required(VERSION 3.10)

project(Spegetti_Renderer)

include_directories(${PROJECT_NAME} PUBLIC "/")

set(Spegetti_Renderer_Sources
	"Sources/Window.cpp"
	"Sources/Camera.cpp"

	"Sources/Shader.cpp"
	"Sources/Material.cpp"
	
	"Sources/Texture.cpp"
	"Sources/G_Buffer.cpp"
	
	"Sources/Vertex.cpp"
	"Sources/Mesh.cpp"
	"Sources/Model.cpp"
	
	"Sources/Debug_Quad.cpp"
	
	"Sources/Post_Process_Effect.cpp"

	"Sources/Spegetti_Renderer.cpp"
	"Headers/Spegetti_Renderer.h"
)

add_library(${PROJECT_NAME} ${Spegetti_Renderer_Sources})

target_link_libraries(${PROJECT_NAME} PRIVATE "GLFW/glfw3")

link_directories("${CMAKE_SOURCE_DIR}/../build/shared")


target_link_libraries(${PROJECT_NAME} PRIVATE "GLAD")

target_link_libraries(${PROJECT_NAME} PRIVATE "Spegetti_Memory")
target_link_libraries(${PROJECT_NAME} PRIVATE "Spegetti_Files")

set_target_properties(${PROJECT_NAME} PROPERTIES
	FOLDER "Engine"

	ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/../build/shared"
	ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/../build/shared"
)
