cmake_minimum_required (VERSION 3.10)
project ("Spegetti")

option(32_BIT "Build for 32-bit devices?" OFF)

set(CMAKE_CXX_STANDARD 17)

if (32_BIT)
	if (WIN32)
		set(CMAKE_GENERATOR_PLATFORM "x86" CACHE STRING "Target platform" FORCE)
	else()
	if (UNIX)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32")
		set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m32")
	endif()
endif()
endif()

link_directories("${CMAKE_SOURCE_DIR}/Third Party")

include_directories(${PROJECT_NAME} PUBLIC "Third Party/GLM")

include_directories(${PROJECT_NAME} PUBLIC "Spegetti_Renderer/Headers")
include_directories(${PROJECT_NAME} PUBLIC "Spegetti_Console/Headers")
include_directories(${PROJECT_NAME} PUBLIC "Spegetti_Files/Headers")

add_subdirectory("Spegetti_Project_Launcher")

add_subdirectory("Spegetti_Renderer")

add_subdirectory("Spegetti_Files")

add_subdirectory("Spegetti_Console")