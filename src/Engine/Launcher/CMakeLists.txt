project("Launcher")

file(GLOB_RECURSE SOURCE "*.c" "*.cpp" "*.h")

add_executable(${PROJECT_NAME} ${SOURCE})

set_target_properties(${PROJECT_NAME} PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../Out"
)