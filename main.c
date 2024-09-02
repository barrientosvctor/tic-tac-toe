#include <raylib.h>
#include "table.h"

static const unsigned short width = 1280, height = 720;

int main(void)
{
    InitWindow(width, height, "Tic Tac Toe");
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Tic Tac Toe Game", (width / 2 - 50), 5, 20, BLACK);
        draw_table();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
