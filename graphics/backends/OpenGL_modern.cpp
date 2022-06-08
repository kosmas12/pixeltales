/*
 * Implementation of the graphics subsystem of Pixeltales using modern OpenGL (Version 3.3)
 */

#include <iostream>
#include "../glad/include/glad/glad.h"
#include "../Graphics.h"
#define MAININCLUDE
#include "OpenGL_common.h"
#undef MAININCLUDE

Graphics::Graphics(int width, int height) {
    if (glfwInit() == GLFW_FALSE) {
        std::cout << "Could not initialize GLFW!" << std::endl;
        exit(1);
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, "Pixeltales (Modern OpenGL)", nullptr, nullptr);
    if (!window) {
        std::cout << "Could not create window!" << std::endl;
        exit(2);
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Could not load OpenGL from drivers!" << std::endl;
        exit(3);
    }

}

void Graphics::renderMap() {

}

void Graphics::renderLoop() {
    glfwPollEvents();
    renderMap();
    if (glfwGetKey(window, GLFW_KEY_ESCAPE)) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

Graphics::~Graphics() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

bool Graphics::shouldExit() {
    return glfwWindowShouldClose(window);
}
