cmake_minimum_required( VERSION 3.10 )
# use the newer OpenGL libraries 
cmake_policy(SET CMP0072 NEW)
project(opengl-learn VERSION 1.0.0)

set(CMAKE_MODULE_PATH $(CMAKE_MODULE_PATH) $(CMAKE_CURRENT_DIR)/cmake)
find_package( OpenGL REQUIRED )
find_package( glfw3 REQUIRED )

add_executable(opengl-learn
  src/main.cpp
)

target_include_directories(opengl-learn PRIVATE dependencies)
target_link_libraries(opengl-learn glfw OpenGL::GL)
