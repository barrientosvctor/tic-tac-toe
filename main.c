#include <raylib.h>

static const unsigned short width = 1280, height = 720;

int main(void)
{
    InitWindow(width, height, "Tic Tac Toe");
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Hello World!", (width / 2), (height / 2), 20, RAYWHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
