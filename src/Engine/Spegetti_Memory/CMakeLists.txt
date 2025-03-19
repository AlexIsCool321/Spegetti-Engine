cmake_minimum_required(VERSION 3.10)

project(Spegetti_Memory)

include_directories(${PROJECT_NAME} PUBLIC "/")

set(Spegetti_Memory_Sources

	"Sources/Spegetti_Memory.cpp"
	"Headers/Spegetti_Memory.h"
)

add_library(${PROJECT_NAME} ${Spegetti_Memory_Sources})

set_target_properties(${PROJECT_NAME} PROPERTIES
	FOLDER "Engine"

	ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/../build/shared"
	ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/../build/shared"
)
