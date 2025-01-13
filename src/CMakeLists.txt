cmake_minimum_required( VERSION 3.10 )
project(opengl-learn VERSION 1.0.0)
cmake_policy(SET CMP0072 NEW)
set(CMAKE_CXX_STANDARD 17) # this does nothing for MSVC, use target_compile_options below
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# Download GLAD
include(FetchContent)
FetchContent_Declare(
    glad
    GIT_REPOSITORY https://github.com/Dav1dde/glad.git
    GIT_TAG v2.0.8
    GIT_PROGRESS TRUE
    SOURCE_SUBDIR cmake
)
FetchContent_MakeAvailable(glad)

glad_add_library(glad_gl_core_33 STATIC REPRODUCIBLE LOADER API gl:core=3.3)
set(GLAD_INSTALL ON)

set(CMAKE_MODULE_PATH $(CMAKE_MODULE_PATH) $(CMAKE_CURRENT_DIR)/cmake)
find_package( OpenGL REQUIRED )
find_package( glfw3 REQUIRED )

add_executable(opengl-learn
  main.cpp
)

target_link_libraries(opengl-learn PUBLIC glfw OpenGL::GL PRIVATE glad_gl_core_33)
target_include_directories(opengl-learn PRIVATE 
    ${glad_SOURCE_DIR}/include
    ${glad_BINARY_DIR}/include
)
