#ifndef GAME_MODULE_HH
#define GAME_MODULE_HH

#include <unordered_map>

#include "id.hh"
#include "game/tile.hh"

struct Terrain {};

// custom games need to implement this class
class GameModule {
public:
    virtual ~GameModule() = default;

    virtual Tile default_tile() const = 0;
    virtual std::pair<size_t, size_t> map_size() const = 0;

protected:
    Id add_terrain_type(Terrain const& t) { terrains_[++id_counter] = t; return id_counter - 1; }

private:
    Id id_counter = 0;
    std::unordered_map<Id, Terrain> terrains_;
};

#endif //GAME_MODULE_HH
