#ifndef TILE_HH
#define TILE_HH

#include "rules/id.hh"

struct Tile {
    Id terrain;
};

static constexpr Tile OUT_OF_BOUNDS = {};

#endif //TILE_HH
