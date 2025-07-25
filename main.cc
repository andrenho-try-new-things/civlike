#include <cstdio>

#include "raylib.h"
#include "raymath.h"
#include "game/game.hh"
#include "sample/sample_game.hh"

static void events();
static void draw();

static SampleGame rules;
static Game game(rules);
static Graphics graphics(rules);

Camera2D camera {};

int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1024, 900, "civlike");
    SetTargetFPS(60);

    camera.zoom = rules.suggested_zoom();

    while (!WindowShouldClose()) {
        events();
        draw();
    }

    CloseWindow();
}

static void events()
{
    if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
        Vector2 delta = GetMouseDelta();
        delta = Vector2Scale(delta, -1.0f/camera.zoom);
        camera.target = Vector2Add(camera.target, delta);
    }

    // Zoom based on mouse wheel
    float wheel = GetMouseWheelMove();
    if (wheel != 0)
    {
        Vector2 mouseWorldPos = GetScreenToWorld2D(GetMousePosition(), camera);
        camera.offset = GetMousePosition();
        camera.target = mouseWorldPos;

        if (wheel < 0 && camera.zoom <= 1.0f)
            camera.zoom /= 2.f;
        else if (wheel > 0 && camera.zoom < 1.0f)
            camera.zoom *= 2.f;
        else if (wheel < 0)
            camera.zoom -= 1.f;
        else if (wheel > 0)
            camera.zoom += 1.f;
        camera.zoom = Clamp(camera.zoom, rules.min_zoom(), rules.max_zoom());
    }
}

static void draw()
{
    BeginDrawing();
    ClearBackground(BLACK);

    BeginMode2D(camera);
    game.draw_tiles(graphics);
    EndMode2D();

    EndDrawing();
}