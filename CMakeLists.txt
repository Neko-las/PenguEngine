cmake_minimum_required(VERSION 3.21)
project(PenguEngine)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenGL REQUIRED)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(externalLibraries/GLFW/glfw-3.3.6)
add_subdirectory(externalLibraries/GLM/glm-master)
add_subdirectory(externalLibraries/GLAD)

add_executable(PenguEngine main.cpp input/keyboardInput.cpp input/mouseInput.cpp window/window.cpp
        rendering/buffer.cpp rendering/renderer.cpp objects/triangle.cpp objects/triangle.hpp rendering/shader.cpp)

target_link_libraries(PenguEngine glfw)
target_link_libraries(PenguEngine glm)
target_link_libraries(PenguEngine glad)

