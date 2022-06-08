#include <iostream>
#include "graphics/Graphics.h"
#include "input/Input.h"

int main() {
    Graphics pixelGraphics(1280, 720);
    Input pixelInput("input.config");

    while (!pixelGraphics.shouldExit()) {
        pixelGraphics.renderLoop();
    }

    return 0;
}
