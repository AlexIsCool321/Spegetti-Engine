cmake_minimum_required(VERSION 3.10)
project(GLAD)

include_directories(${PROJECT_NAME} PUBLIC "/")
include_directories(${PROJECT_NAME} PUBLIC "Headers")

set(GLAD_Sources
	"Sources/glad.c"
)

add_library(${PROJECT_NAME} ${GLAD_Sources})

set_target_properties(${PROJECT_NAME} PROPERTIES
	FOLDER "Third Party"

	ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/../build/shared"
	ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/../build/shared"
)
