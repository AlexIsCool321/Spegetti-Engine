project("MGL_GLAD")

file(GLOB_RECURSE SOURCE CONFIGURE_DEPENDS "*.c" "*.h")

add_library(${PROJECT_NAME} SHARED ${SOURCE})

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Headers")

set_target_properties(${PROJECT_NAME} PROPERTIES
	FOLDER "Third Party/GLAD/MGL"
	
	LIBRARY_OUTPUT_DIRECTORY	"${CMAKE_SOURCE_DIR}/../OUT/bin"
)

add_library(MGL::library ALIAS ${PROJECT_NAME})
