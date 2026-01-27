project("Launcher")

file(GLOB_RECURSE SOURCE "*.c" "*.cpp" "*.h" "*.hpp")

add_executable(${PROJECT_NAME} ${SOURCE})

target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/Headers")

target_link_libraries(${PROJECT_NAME} PUBLIC Engine::library)

set_target_properties(${PROJECT_NAME} PROPERTIES
	FOLDER "Engine"
	
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../Out"
)