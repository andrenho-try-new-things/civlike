#ifndef GAME_HH
#define GAME_HH

#include <vector>

#include "tile.hh"

class GameModule;

class Game {
public:
    explicit Game(GameModule* game_module);

private:
    GameModule const* game_module_;

    size_t map_w_, map_h_;
    std::vector<Tile> tiles_;
};

#endif //GAME_HH
