set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../OUT/bin)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
set(GLFW_LIBRARY_TYPE SHARED CACHE INTERNAL "Build GLFW as a shared library")

FetchContent_Declare(
	GLFW
	GIT_REPOSITORY https://github.com/glfw/glfw.git
	GIT_TAG 3.4
	GIT_SHALLOW ON
)

FetchContent_MakeAvailable(GLFW)

set_target_properties(glfw PROPERTIES FOLDER "Third Party/GLFW")
set_target_properties(update_mappings PROPERTIES FOLDER "Third Party/GLFW")

add_library(GLFW::library ALIAS glfw)