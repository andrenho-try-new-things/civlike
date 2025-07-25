#include "graphics.hh"

void Graphics::set_rel(ssize_t x, ssize_t y)
{
    rel_x_ = x;
    rel_y_ = y;
}

void Graphics::draw_rectangle(int x, int y, int w, int h, Color color) const
{
    DrawRectangle(x + rel_x_, y + rel_y_, w, h, color);
}

void Graphics::draw_pixel(int x, int y, Color color) const
{
    DrawPixel(x + rel_x_, y + rel_y_, color);
}
