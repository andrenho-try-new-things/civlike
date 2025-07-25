#include "sample_game.hh"

SampleGame::SampleGame()
{
    grassland = add_terrain_type({});
    ocean = add_terrain_type({});
}

void SampleGame::draw_tile(Graphics const& graphics, std::array<Tile, 9> const& tiles) const
{
    Tile const& center = tiles[5];
    if (center.terrain == grassland)
        graphics.draw_rectangle(0, 0, TILE_SIZE, TILE_SIZE, { 128, 255, 128, 255 });
    else if (center.terrain == ocean)
        graphics.draw_rectangle(0, 0, TILE_SIZE, TILE_SIZE, { 128, 128, 255, 255 });

    graphics.draw_pixel(TILE_SIZE - 1, TILE_SIZE - 1, BLACK);
    graphics.draw_pixel(TILE_SIZE - 2, TILE_SIZE - 1, BLACK);
    graphics.draw_pixel(TILE_SIZE - 1, TILE_SIZE - 2, BLACK);
}
