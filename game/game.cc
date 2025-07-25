#include "game.hh"

#include "rules/game_rules.hh"

Game::Game(GameRules const& rules)
    : rules_(rules)
{
    auto [w, h] = rules_.map_size();
    map_w_ = w;
    map_h_ = h;
    tiles_.insert(tiles_.begin(), map_w_ * map_h_, rules_.default_tile());
}

void Game::draw_tiles(Graphics& graphics) const
{
    auto const [tile_w, tile_h] = rules_.tile_size();

    for (ssize_t x = 0; x < map_w_; ++x) {
        for (ssize_t y = 0; y < map_h_; ++y) {
            graphics.set_rel(x * tile_w, y * tile_h);
            std::array<Tile, 9> tiles = {
                tile(x - 1, y - 1), tile(x, y - 1), tile(x + 1, y - 1),
                tile(x - 1, y), tile(x, y), tile(x + 1, y),
                tile(x - 1, y + 1), tile(x, y + 1), tile(x + 1, y + 1),
            };
            rules_.draw_tile(graphics, tiles);
        }
    }
}

Tile const& Game::tile(ssize_t x, ssize_t y) const
{
    if (x < 0 || y < 0 || x >= map_w_ || y >= map_h_)
        return OUT_OF_BOUNDS;

    return tiles_[y * map_w_ + x];
}