#include <raylib.h>
#include "table.h"
#include "utils.h"


void draw_table() {
    Vector2 start = {.x = 600, .y = 200};
    Vector2 end = {.x = start.x, .y = start.y + BOX_HEIGHT * 3 };
    Rectangle button = {0};
        
    // Vertical lines rendering
    for (int i = 0; i < 2; ++i, start.x += BOX_WIDTH, end.x += BOX_WIDTH)
    {
        DrawLineV(start, end, BLACK);
    }
    
    start.x -= BOX_WIDTH * 3; // Sets the x coordinate of the start vector to the beginning of the first box at the up-left side.
    start.y += BOX_HEIGHT; // Sets the y coordinate of the start vector to the bottom of the first box.
    end.y = start.y;
    
    button.x = start.x;
    button.y = start.y - BOX_HEIGHT; // Starts from the box (1,1) of tic tac toe.
    button.width = BOX_WIDTH;
    button.height = BOX_HEIGHT;

    // Horizontal lines rendering
    for (int i = 0; i < 2; ++i, start.y += BOX_HEIGHT, end.y += BOX_HEIGHT) {
        DrawLineV(start, end, BLACK);
    }

    // Drawing buttons
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++, button.x += BOX_WIDTH)
        {
            DrawRectangle(button.x, button.y, button.width, button.height, RED_LOW_OPACITY);
        }

        button.x -= BOX_WIDTH * 3;
        button.y += BOX_HEIGHT;
    }
}
