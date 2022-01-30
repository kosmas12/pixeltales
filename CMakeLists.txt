cmake_minimum_required(VERSION 3.21)
project(Pixeltales)

set(CMAKE_CXX_STANDARD 11)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

option(OPENGL_MODERN "Use the modern OpenGL backend for graphics" ON)

add_executable(Pixeltales main.cpp)

if (OPENGL_MODERN)
    get_target_property(PIXELSOURCES Pixeltales SOURCES)
    target_sources(Pixeltales PRIVATE graphics/backends/OpenGL_modern.cpp graphics/glad/src/glad.c)
    target_link_libraries(Pixeltales OpenGL::GL glfw ${CMAKE_DL_LIBS})
endif()
