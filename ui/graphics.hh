#ifndef GRAPHICS_HH
#define GRAPHICS_HH

#include <sys/types.h>
#include <unordered_map>
#include <bits/basic_string.h>

#include "raylib.h"

#include "rules/id.hh"

class GameRules;

class Graphics {
public:
    explicit Graphics(GameRules const& rules) : rules_(rules) {}

    void set_rel(ssize_t x, ssize_t y);
    void draw_rectangle(int x, int y, int w, int h, Color color) const;
    void draw_pixel(int x, int y, Color color) const;
    void draw_atlas_image(int x, int y, Id atlas_image) const;

private:
    GameRules const&                  rules_;
    ssize_t                           rel_x_ = 0, rel_y_ = 0;
    std::unordered_map<Id, Texture2D> textures_;

    std::string find_file(std::string const& filename) const;
};

#endif //GRAPHICS_HH
