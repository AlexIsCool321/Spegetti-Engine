cmake_minimum_required(VERSION 3.10)

project(Spegetti_Entity_System)

include_directories(${PROJECT_NAME} PUBLIC "/")

set(Spegetti_Entity_System_Sources

	"Sources/Spegetti_Entity_System.cpp"
	"Headers/Spegetti_Entity_System.h"
)

add_library(${PROJECT_NAME} ${Spegetti_Entity_System_Sources})

set_target_properties(${PROJECT_NAME} PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/../build/shared"
	ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/../build/shared"
)
