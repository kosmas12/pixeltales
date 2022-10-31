#version 330 core
layout (location = 0) in vec3 inPos;
out vec2 texCoord;

void main() {
    gl_Position = vec4(inPos, 1.0);
    texCoord = vec2(inPos.x, inPos.y);
}
