#include "sample_game.hh"

SampleGame::SampleGame()
{
    // terrain
    grassland = add_terrain_type({});
    ocean = add_terrain_type({});

    // images
    atlas = add_image("terrain_atlas.png");
    img_ocean[0] = add_atlas_rect(atlas, 224, 384, 32, 32);
    img_ocean[1] = add_atlas_rect(atlas, 672, 544, 32, 32);
    img_ocean[2] = add_atlas_rect(atlas, 704, 544, 32, 32);
    img_ocean[3] = add_atlas_rect(atlas, 736, 544, 32, 32);
    img_grassland[0] = add_atlas_rect(atlas, 704, 96, 32, 32);
    img_grassland[1] = add_atlas_rect(atlas, 704, 160, 32, 32);
    img_grassland[2] = add_atlas_rect(atlas, 736, 160, 32, 32);
    img_grassland[3] = add_atlas_rect(atlas, 736, 352, 32, 32);
}

void SampleGame::draw_tile(Graphics const& graphics, std::array<Tile, 9> const& tiles) const
{
    Tile const& center = tiles[5];
    if (center.terrain == grassland)
        graphics.draw_rectangle(0, 0, TILE_SIZE, TILE_SIZE, { 128, 255, 128, 255 });
    else if (center.terrain == ocean)
        graphics.draw_atlas_image(0, 0, img_ocean[0]);
        // graphics.draw_rectangle(0, 0, TILE_SIZE, TILE_SIZE, { 128, 128, 255, 255 });

    graphics.draw_pixel(TILE_SIZE - 1, TILE_SIZE - 1, BLACK);
    graphics.draw_pixel(TILE_SIZE - 2, TILE_SIZE - 1, BLACK);
    graphics.draw_pixel(TILE_SIZE - 1, TILE_SIZE - 2, BLACK);
}

void SampleGame::draw_map(size_t w, size_t h, std::vector<Tile>& tiles) const
{
    tile(tiles, w, 3, 3) = Tile { grassland };
    tile(tiles, w, 4, 3) = Tile { grassland };
}
