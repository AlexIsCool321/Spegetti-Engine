project("Engine")

file(GLOB_RECURSE SOURCE "*.c" "*.cpp" "*.h" "*.hpp")

set("ProjectName" "${PROJECT_NAME}_Client")

add_library(${ProjectName} SHARED ${SOURCE})

target_include_directories(${ProjectName} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Headers")

target_link_libraries(${ProjectName} PUBLIC Engine::library)
set_target_properties(${ProjectName} PROPERTIES
	FOLDER "Games"
	
	LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../Out/${PROJECT_NAME}"
	LIBRARY_OUTPUT_NAME Client
)