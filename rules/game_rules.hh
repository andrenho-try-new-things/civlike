#ifndef GAME_MODULE_HH
#define GAME_MODULE_HH

#include <array>
#include <string>
#include <unordered_map>

#include "id.hh"
#include "game/tile.hh"
#include "ui/graphics.hh"

struct Terrain {};
struct AtlasRect { Id image; int x, y, w, h; };

// custom games need to implement this class

class GameRules {
public:
    virtual ~GameRules() = default;

    // game parameters
    virtual Tile default_tile() const = 0;
    virtual std::pair<size_t, size_t> map_size() const = 0;

    // UI
    virtual float suggested_zoom() const { return 2; }
    virtual float min_zoom() const { return 0.5; }
    virtual float max_zoom() const { return 4; }
    virtual std::pair<size_t, size_t> tile_size() const = 0;
    virtual void draw_tile(Graphics const& graphics, std::array<Tile, 9> const& tiles) const = 0;

    // getters
    [[nodiscard]] std::string image(Id id) const { return images_.at(id); }
    [[nodiscard]] AtlasRect atlas_rect(Id id) const { return atlas_rects_.at(id); }

protected:
    Id add_terrain_type(Terrain const& t) { terrains_[++id_counter] = t; return id_counter - 1; }
    Id add_image(std::string const& path) { images_[++id_counter] = path; return id_counter - 1; }
    Id add_atlas_rect(Id image, int x, int y, int w, int h) { atlas_rects_[++id_counter] = { image, x, y, w, h }; return id_counter - 1; }

private:
    Id id_counter = 0;
    std::unordered_map<Id, Terrain>     terrains_;
    std::unordered_map<Id, std::string> images_;
    std::unordered_map<Id, AtlasRect>   atlas_rects_;
};

#endif //GAME_MODULE_HH
