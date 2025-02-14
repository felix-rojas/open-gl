cmake_minimum_required(VERSION 3.10)
project(opengl-learn VERSION 1.0.0)
cmake_policy(SET CMP0072 NEW)
set(CMAKE_CXX_STANDARD 17) # this does nothing for MSVC, use
                           # target_compile_options below
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(BUILD_MODE debug)
set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

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

# Download GLFW
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw
    GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(glfw)

# Set GLFW options
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")

# Find OpenGL
find_package(OpenGL REQUIRED)

# Create executable
add_executable(opengl-learn main.cpp)

# Link libraries
target_link_libraries(
  opengl-learn
  PUBLIC glfw OpenGL::GL
  PRIVATE glad_gl_core_33
)

# Include directories
target_include_directories(opengl-learn PRIVATE ${glad_SOURCE_DIR}/include
                                                ${glad_BINARY_DIR}/include)
