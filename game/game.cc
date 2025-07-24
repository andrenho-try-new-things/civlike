#include "game.hh"

#include "module/game_module.hh"

Game::Game(GameModule*game_module)
    : game_module_(game_module)
{
    auto [w, h] = game_module_->map_size();
    map_w_ = w;
    map_h_ = h;
    tiles_.insert(tiles_.begin(), map_w_ * map_h_, game_module_->default_tile());
}
