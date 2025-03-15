cmake_minimum_required(VERSION 3.10)

project(Spegetti_Files)

include_directories(${PROJECT_NAME} PUBLIC "/")

set(Spegetti_Files_Sources

	"Sources/Spegetti_Files.cpp"
	"Headers/Spegetti_Files.h"
)

add_library(${PROJECT_NAME} ${Spegetti_Files_Sources})

set_target_properties(${PROJECT_NAME} PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/../build/shared"
	ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/../build/shared"
)
