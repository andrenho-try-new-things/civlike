#ifndef SAMPLE_GAME_HH
#define SAMPLE_GAME_HH

#include "rules/game_rules.hh"

class SampleGame : public GameRules {
public:
    SampleGame();

    Tile default_tile() const override { return { .terrain = ocean }; }
    std::pair<size_t, size_t> map_size() const override { return { 30, 30 }; }

    std::pair<size_t, size_t> tile_size() const override { return { TILE_SIZE, TILE_SIZE }; }
    void draw_tile(Graphics const& graphics, std::array<Tile, 9> const& tiles) const override;

private:
    Id grassland, ocean;

    static constexpr size_t TILE_SIZE = 32;
};

#endif //SAMPLE_GAME_HH
