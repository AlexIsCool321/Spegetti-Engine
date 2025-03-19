cmake_minimum_required (VERSION 3.10)
project ("Spegetti")

set(CMAKE_CXX_STANDARD 17)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Third Party
link_directories("${CMAKE_SOURCE_DIR}/Third Party")

include_directories(${PROJECT_NAME} PUBLIC "Third Party/STB_IMAGE/Headers")

include_directories(${PROJECT_NAME} PUBLIC "Third Party/KHR/Headers")
include_directories(${PROJECT_NAME} PUBLIC "Third Party/GLAD/Headers")

include_directories(${PROJECT_NAME} PUBLIC "Third Party/GLFW/Headers")

include_directories(${PROJECT_NAME} PUBLIC "Third Party/GLM/Headers")
include_directories(${PROJECT_NAME} PUBLIC "Third Party/IMGUI/Headers")


# Engine
include_directories(${PROJECT_NAME} PUBLIC "Engine/Launcher/Headers")
include_directories(${PROJECT_NAME} PUBLIC "Engine/Spegetti_Memory/Headers")
include_directories(${PROJECT_NAME} PUBLIC "Engine/Spegetti_Renderer/Headers")
include_directories(${PROJECT_NAME} PUBLIC "Engine/Spegetti_Files/Headers")
include_directories(${PROJECT_NAME} PUBLIC "Engine/Spegetti_Logic/Headers")
include_directories(${PROJECT_NAME} PUBLIC "Engine/Spegetti_Console/Headers")
include_directories(${PROJECT_NAME} PUBLIC "Engine/Spegetti_Map_System/Headers")
include_directories(${PROJECT_NAME} PUBLIC "Engine/Spegetti_Entity_System/Headers")

add_subdirectory("Engine/Launcher")

add_subdirectory("Engine/Spegetti_Memory")

add_subdirectory("Engine/Spegetti_Renderer")

add_subdirectory("Engine/Spegetti_Files")

add_subdirectory("Engine/Spegetti_Console")

add_subdirectory("Engine/Spegetti_Logic")

add_subdirectory("Engine/Spegetti_Map_System")

add_subdirectory("Engine/Spegetti_Entity_System")


# Tools
include_directories(${PROJECT_NAME} PUBLIC "Tools/Engine/Headers")
include_directories(${PROJECT_NAME} PUBLIC "Tools/UV_Viewer/Headers")

add_subdirectory("Tools/Engine")
add_subdirectory("Tools/UV_Viewer")