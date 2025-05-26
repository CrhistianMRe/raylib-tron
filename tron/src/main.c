#include "../include/raylib.h"
#include "controller.c"

int main() {
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
    InitWindow(1000, 1000, "Demo Tron");
    while (!WindowShouldClose()) {

        SetTargetFPS(60);
        //printf("Numero enter ooooiio%d\n", argc);
        initController();
        BeginDrawing();
        ClearBackground(BLACK);


        EndDrawing();
    }

    CloseWindow();
    return 0;
}
