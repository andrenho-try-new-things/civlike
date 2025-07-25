#ifndef GRAPHICS_HH
#define GRAPHICS_HH

#include "raylib.h"
#include <sys/types.h>

class Graphics {
public:
    void set_rel(ssize_t x, ssize_t y);
    void draw_rectangle(int x, int y, int w, int h, Color color) const;

private:
    ssize_t rel_x_ = 0, rel_y_ = 0;
};

#endif //GRAPHICS_HH
