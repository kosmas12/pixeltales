//
// Created by kosmas on 29/6/2022.
//

#ifndef PIXELTALES_SHADERPROGRAM_H
#define PIXELTALES_SHADERPROGRAM_H

#include <string>
#include <glm/glm.hpp>

class ShaderProgram {
    int vertexShader;
    int fragmentShader;
    int program;
public:
    ShaderProgram(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
    void compileShader(const std::string &sourceFilePath, int type);
    void linkProgram();
    void use();
};


#endif //PIXELTALES_SHADERPROGRAM_H
