cmake_minimum_required(VERSION 3.10)
project(IMGUI)

include_directories(${PROJECT_NAME} PUBLIC "/")
include_directories(${PROJECT_NAME} PUBLIC "Headers")
include_directories(${PROJECT_NAME} PUBLIC "Headers/imgui")

set(IMGUI_Sources
    "Headers/imgui/imgui.h"

    "Headers/imgui/imgui.cpp"
    "Headers/imgui/imgui_draw.cpp"
    "Headers/imgui/imgui_widgets.cpp"
    "Headers/imgui/imgui_tables.cpp"
    "Headers/imgui/imgui_demo.cpp"
    "Headers/imgui/imgui_widgets.cpp"
    "Headers/imgui/backends/imgui_impl_glfw.cpp"
    "Headers/imgui/backends/imgui_impl_opengl3.cpp"

    "Headers/imgui/backends/imgui_impl_opengl3.h"
    "Headers/imgui/backends/imgui_impl_glfw.h"
)

add_library(${PROJECT_NAME} ${IMGUI_Sources})

target_link_libraries(${PROJECT_NAME} PRIVATE "GLFW/glfw3")

set_target_properties(${PROJECT_NAME} PROPERTIES
    FOLDER "Third Party"

    ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/../build/shared"
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/../build/shared"
)
