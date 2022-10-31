/*
 * Implementation of the graphics subsystem of Pixeltales using modern OpenGL (Version 3.3)
 */

#include <iostream>
#include "../../../glad/include/glad/glad.h"
#include "../../../Graphics.h"
#define MAININCLUDE
#include "../OpenGL_common.h"
#undef MAININCLUDE
#include "../../../ShaderProgram.h"
#define STB_IMAGE_IMPLEMENTATION
#include "../../../stb_image.h"

ShaderProgram *backgroundProgram;

void loadBackground() {
    glGenTextures(1, &backgroundTexture);
    glBindTexture(GL_TEXTURE_2D, backgroundTexture);
    stbi_set_flip_vertically_on_load(true);
    int textureWidth, textureHeight, numChannels;
    unsigned char *data = stbi_load("data/textures/background1080p.png", &textureWidth, &textureHeight,
                                    &numChannels, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, textureWidth, textureHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        stbi_image_free(data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    }
    else {
        std::cerr << "Failed to load background texture" << std::endl;
        exit(4);
    }

    float mapVertices[] = {
            1.0f, 1.0f, 0.0f,
            1.0f, -1.0f, 0.0f,
            -1.0f, -1.0f, 0.0f,
            -1.0f, 1.0f, 0.0f
    };

    unsigned int indices[] = {
            0, 1, 3, // First half
            1, 2, 3  // Second half
    };

    glGenVertexArrays(1, &backgroundVAO);
    glGenBuffers(1, &backgroundVBO);
    glBindVertexArray(backgroundVAO);
    glBindBuffer(GL_ARRAY_BUFFER, backgroundVBO);
    glGenBuffers(1, &backgroundEBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, backgroundEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    glBufferData(GL_ARRAY_BUFFER, sizeof(mapVertices), mapVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)(0));
    glEnableVertexAttribArray(0);

    backgroundProgram = new ShaderProgram("shaders/backgroundVertex.glsl", "shaders/backgroundFragment.glsl");

}

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
    loadBackground();
}

void Graphics::renderBackground() {
    glBindVertexArray(backgroundVAO);
    glActiveTexture(GL_TEXTURE0);
    backgroundProgram->use();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}

void Graphics::renderLoop() {
    glfwPollEvents();
    renderBackground();
    if (glfwGetKey(window, GLFW_KEY_ESCAPE)) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
    glfwSwapBuffers(window);
}

Graphics::~Graphics() {
    glDeleteTextures(1, &backgroundTexture);
    glfwDestroyWindow(window);
    glfwTerminate();
}

bool Graphics::shouldExit() {
    return glfwWindowShouldClose(window);
}
