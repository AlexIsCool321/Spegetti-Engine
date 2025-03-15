cmake_minimum_required(VERSION 3.10)

project(Spegetti_Logic)

include_directories(${PROJECT_NAME} PUBLIC "/")

set(Spegetti_Logic_Sources

	"Sources/Spegetti_Logic.cpp"
	"Headers/Spegetti_Logic.h"
)

add_library(${PROJECT_NAME} ${Spegetti_Logic_Sources})

set_target_properties(${PROJECT_NAME} PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/../build/shared"
	ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/../build/shared"
)
