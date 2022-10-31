//
// Created by kosmas on 30/6/2022.
//

#include <fstream>
#include <sstream>
#include <iostream>
#include "../../../glad/include/glad/glad.h"
#include "../../../ShaderProgram.h"

ShaderProgram::ShaderProgram(const std::string &vertexShaderPath, const std::string &fragmentShaderPath) {
    this->compileShader(vertexShaderPath, GL_VERTEX_SHADER);
    this->compileShader(fragmentShaderPath, GL_FRAGMENT_SHADER);
    this->linkProgram();
}

void ShaderProgram::linkProgram() {
    this->program = glCreateProgram();
    glAttachShader(this->program, this->vertexShader);
    glAttachShader(this->program, this->fragmentShader);
    glLinkProgram(this->program);

    char errorLog[1024];
    int success;
    glGetProgramiv(this->program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(this->program, 1024, nullptr, errorLog);
        std::cerr << "Error linking shader program: \n" << errorLog << std::endl;
        exit(2);
    }
    else {
        glDeleteShader(this->vertexShader);
        glDeleteShader(this->fragmentShader);
    }
}

void ShaderProgram::compileShader(const std::string &sourceFilePath, int type) {
    std::ifstream sourceFile(sourceFilePath);
    std::string source;
    std::stringstream sourceStream;
    sourceStream << sourceFile.rdbuf();
    sourceFile.close();
    source = sourceStream.str();
    const char *sourceAsCharArray = source.c_str();
    int *shader;

    if (type == GL_VERTEX_SHADER) {
        shader = &(this->vertexShader);
    }
    else {
        shader = &(this->fragmentShader);
    }

    *shader = glCreateShader(type);
    glShaderSource(*shader, 1, &sourceAsCharArray, nullptr);
    glCompileShader(*shader);
    char errorLog[1024];
    int success;
    glGetShaderiv(*shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(*shader, 1024, nullptr, errorLog);
        std::cerr << "Error compiling ";
        if (type == GL_FRAGMENT_SHADER) {
            std::cerr << "fragment ";
        }
        else {
            std::cerr << "vertex ";
        }
        std::cerr << "shader: \n" << errorLog << std::endl;
        exit(1);
    }
}

void ShaderProgram::use() {
    glUseProgram(this->program);
}
