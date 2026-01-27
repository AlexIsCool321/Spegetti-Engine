project("Engine")

file(GLOB_RECURSE SOURCE "*.c" "*.cpp" "*.h" "*.hpp")

add_library(${PROJECT_NAME} SHARED ${SOURCE})

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Headers")

target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)

set_target_properties(${PROJECT_NAME} PROPERTIES
	FOLDER "Engine"
	
	LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../Out/bin"
)

add_library(${PROJECT_NAME}::library ALIAS ${PROJECT_NAME})