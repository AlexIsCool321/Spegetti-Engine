project("Demo")

file(GLOB_RECURSE SOURCE "*.c" "*.cpp" "*.h" "*.hpp")

add_library(Client SHARED ${SOURCE})

target_include_directories(Client PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Headers")

target_link_libraries(Client PUBLIC Engine::library)

set_target_properties(Client PROPERTIES
	LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../Out/${PROJECT_NAME}"
)