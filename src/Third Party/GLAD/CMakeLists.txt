project("GLAD")

set(Python3_EXECUTABLE "/usr/bin/python" CACHE FILEPATH "Python interpreter")

set(BUILD_SHARED_LIBS ON CACHE BOOL "")

FetchContent_Declare(
	glad
	GIT_REPOSITORY https://github.com/Dav1dde/glad.git
	GIT_TAG v2.0.8
	GIT_SHALLOW TRUE
	GIT_PROGRESS TRUE

	SOURCE_SUBDIR cmake
)

FetchContent_MakeAvailable(glad)

glad_add_library(gladGL STATIC REPRODUCIBLE LOADER API gl:core=4.3)
glad_add_library(gladVK STATIC REPRODUCIBLE LOADER API vulkan=1)

set_target_properties(gladGL PROPERTIES
	FOLDER "Third Party/GLAD"
)

set_target_properties(gladVK PROPERTIES
	FOLDER "Third Party/GLAD"
)