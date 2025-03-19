cmake_minimum_required(VERSION 3.10)

project(Spegetti_Console)

include_directories(${PROJECT_NAME} PUBLIC "/")

set(Spegetti_Console_Sources

	"Sources/Spegetti_Console.cpp"
	"Headers/Spegetti_Console.h"
)

add_library(${PROJECT_NAME} ${Spegetti_Console_Sources})

set_target_properties(${PROJECT_NAME} PROPERTIES
	FOLDER "Engine"

	ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/../build/shared"
	ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/../build/shared"
)
