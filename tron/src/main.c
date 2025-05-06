#include "raylib.h"
#include "controller.c"

int main() {
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

    InitWindow(500, 500, "Demo Tron");



    while (!WindowShouldClose()) {
        //updateGame();  //

        initGame();
        BeginDrawing();
        ClearBackground(BLACK);


        EndDrawing();
    }

    CloseWindow();
    return 0;
}
