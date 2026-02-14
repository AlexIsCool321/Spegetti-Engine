project("GL_Renderer")

file(GLOB_RECURSE SOURCE "*.c" "*.h")

add_library(${PROJECT_NAME} SHARED ${SOURCE})

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Headers")

target_link_libraries(${PROJECT_NAME} PRIVATE Core::library)

set_target_properties(${PROJECT_NAME} PROPERTIES
	FOLDER "Plugins"
	
	LIBRARY_OUTPUT_DIRECTORY	"${CMAKE_SOURCE_DIR}/../OUT/plugins"
)

add_library(${PROJECT_NAME}::library ALIAS ${PROJECT_NAME})