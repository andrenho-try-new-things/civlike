#ifndef SAMPLE_GAME_HH
#define SAMPLE_GAME_HH
#include "module/game_module.hh"

class SampleGame : public GameModule {
public:
    SampleGame();

    Tile default_tile() const override { return { .terrain = ocean }; }

    std::pair<size_t, size_t> map_size() const override { return { 30, 30 }; }

private:
    Id grassland, ocean;
};

#endif //SAMPLE_GAME_HH
