#include "raylib.h"
#include "game/game.hh"
#include "sample/sample_game.hh"

static void events();
static void draw();

static SampleGame sample_game;
static Game game(&sample_game);

int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1024, 900, "civlike");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        events();
        draw();
    }

    CloseWindow();
}

static void events()
{

}

static void draw()
{
    BeginDrawing();
    ClearBackground(BLACK);
    game.draw_tiles();
    EndDrawing();
}