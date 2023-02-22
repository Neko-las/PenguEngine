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

add_executable(PenguEngine src/main.cpp src/input/keyboardInput.cpp src/input/mouseInput.cpp src/window/window.cpp
        src/rendering/renderer.cpp src/objects/triangle.cpp src/objects/triangle.hpp src/rendering/shader/shader.cpp src/rendering/buffer/VertexBuffer.hpp src/rendering/buffer/VertexArray.hpp src/rendering/buffer/ElementBuffer.hpp src/rendering/buffer/ElementBuffer.cpp src/rendering/buffer/VertexArray.cpp src/rendering/buffer/VertexBuffer.cpp)

target_link_libraries(PenguEngine glfw)
target_link_libraries(PenguEngine glm)
target_link_libraries(PenguEngine glad)

