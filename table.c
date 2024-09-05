#include <raylib.h>
#include "table.h"

void draw_table() {
    Vector2 start = {.x = 600, .y = 200};
    Vector2 end = {.x = start.x, .y = start.y + BOX_HEIGHT * 3 };

    // Vertical lines rendering
    for (int i = 0; i < 2; ++i, start.x += BOX_WIDTH, end.x += BOX_WIDTH)
    {
        DrawLineV(start, end, BLACK);
    }

    start.x -= BOX_WIDTH * 3; // Sets the x coordinate of the start vector to the beginning of the first box at the up-left side.
    start.y += BOX_HEIGHT; // Sets the y coordinate of the start vector to the bottom of the first box.
    end.y = start.y;

    // Horizontal lines rendering
    for (int i = 0; i < 2; ++i, start.y += BOX_HEIGHT, end.y += BOX_HEIGHT) {
        DrawLineV(start, end, BLACK);
    }
}
