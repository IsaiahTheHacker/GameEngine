cmake_minimum_required(VERSION 3.10)
# Project name
project(GameEngine)

# C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(OpenGL_GL_PREFERENCE GLVND)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
# Executable
add_executable(Engine Engine.c)

target_link_libraries(Engine glfw GL m)
