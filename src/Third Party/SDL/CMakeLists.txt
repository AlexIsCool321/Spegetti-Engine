set(SDL_OUTPUT_DIR "${CMAKE_SOURCE_DIR}/../Out/Game/Bin")

set(SDL_SHARED ON CACHE BOOL "" FORCE)
set(SDL_STATIC OFF CACHE BOOL "" FORCE)
set(SDL_TEST OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    SDL3
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-3.4.0
)

FetchContent_MakeAvailable(SDL3)