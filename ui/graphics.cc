#include "graphics.hh"

#include "rules/game_rules.hh"

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

void Graphics::draw_atlas_image(int x, int y, Id atlas_image) const
{
    AtlasRect a = rules_.atlas_rect(atlas_image);
    Texture2D texture;

    auto it = textures_.find(a.image);
    if (it == textures_.end()) {
        std::string path = find_file(rules_.image(a.image));
        texture = LoadTexture(path.c_str());  // TODO - change this to load from binary
    } else {
        texture = it->second;
    }

    DrawTexture(texture, x + rel_x_, y + rel_y_, WHITE);
}

std::string Graphics::find_file(std::string const& filename) const
{
    return "sample/" + filename;  // TODO
}
