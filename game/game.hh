#ifndef GAME_HH
#define GAME_HH

#include <sys/types.h>
#include <vector>

#include "tile.hh"
#include "ui/graphics.hh"

class GameRules;

class Game {
public:
    explicit Game(GameRules const& rules);

    void draw_tiles(Graphics& graphics) const;

private:
    GameRules const& rules_;
    size_t map_w_, map_h_;
    std::vector<Tile> tiles_;

    [[nodiscard]] Tile const& tile(ssize_t x, ssize_t y) const;
};

#endif //GAME_HH
