//
// Created by kosmas on 25/1/22.
//

#ifndef PIXELTALES_GRAPHICS_H
#define PIXELTALES_GRAPHICS_H


class Graphics {
private:
    void renderMap();

public:
    Graphics(int width, int height);
    ~Graphics();
    void renderLoop();
    bool shouldExit();
};


#endif //PIXELTALES_GRAPHICS_H
