#include "../include/raylib.h"
#include "controller.c"

int main() {
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
    InitWindow(1000, 1000, "Demo Tron");

    Image image = LoadImage("resources/TronGame.png");
    Texture2D texture = LoadTextureFromImage(image);
    UnloadImage(image);

    while (!WindowShouldClose()) {

        SetTargetFPS(60);

        BeginDrawing();
        ClearBackground(BLACK);
        initController(texture);
        EndDrawing();
    }

    UnloadTexture(texture);
    CloseWindow();
    return 0;
}
