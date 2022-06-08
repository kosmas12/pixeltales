cmake_minimum_required(VERSION 3.21)
project(Pixeltales)

set(CMAKE_CXX_STANDARD 20)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

option(USE_OPENGL_MODERN "Use the modern OpenGL backend for graphics" ON)
option(USE_GLFW_INPUT "Use the GLFW backend for input" ON)

add_executable(Pixeltales main.cpp)

if (USE_OPENGL_MODERN)
    get_target_property(PIXELSOURCES Pixeltales SOURCES)
    target_sources(Pixeltales PRIVATE graphics/backends/OpenGL_modern.cpp graphics/glad/src/glad.c)
    target_link_libraries(Pixeltales OpenGL::GL glfw ${CMAKE_DL_LIBS})
endif()

if(USE_GLFW_INPUT)
    target_sources(Pixeltales PRIVATE input/backends/GLFW.cpp)
    # GLFW is already linked from the Vulkan or OpenGL settings, no need to specify again
endif()
