#include <raylib.h>
#include "table.h"

void draw_table() {
    // TODO: Make the calculus needed to draw the table correctly independent of the initial x-y coords of the Vector.
    Vector2 start = {.x = 550, .y = 300},
    end = {.x = start.x, .y = 600};
    for (int i = 0; i < 2; ++i, start.x += 100, end.x += 100)
    {
        DrawLineV(start, end, BLACK);
    }

    start.x = start.x - 100 * 3;
    start.y = start.y + 100;
    end.y = start.y;

    for (int i = 0; i < 2; ++i, start.y += 100, end.y += 100) {
        DrawLineV(start, end, BLACK);
    }
}
