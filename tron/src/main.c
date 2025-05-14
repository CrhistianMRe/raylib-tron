#include "raylib.h"
#include "controller.c"

int main(int argc, char* argv[]) {
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

    InitWindow(1000, 1000, "Demo Tron");



    while (!WindowShouldClose()) {
        //updateGame();  //

        SetTargetFPS(60);
        //printf("Numero enter ooooiio%d\n", argc);
        initGame(argc, argv);
        BeginDrawing();
        ClearBackground(BLACK);


        EndDrawing();
    }

    CloseWindow();
    return 0;
}
