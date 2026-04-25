#include <stdlib.h>

#include <raylib.h>

#include "table.h"
#include "utils.h"

#define BOX_WIDTH 100
#define BOX_HEIGHT 100
#define BOX_AMOUNT 9

static Rectangle** buttons = NULL;
static Texture2D* button_textures = NULL;
static int buttons_counter = 0;

/*
 * Get_table_starting_position: gets the starting position of the table.
 * 
 * NOTE: 2D vector returned by this function indicates the coordenates of the
 * first line separator of the table (top, left side, between first and second box)
 */
static Vector2 Get_table_separator_starting_position(void)
{
    return (Vector2) { GetRenderWidth() / 2.0f - BOX_WIDTH / 2.0f, GetRenderHeight() / 2.0f - BOX_HEIGHT / 2.0f };
}

/*
 * Get_table_starting_position: gets the starting position of the table.
 *
 * NOTE: 2D vector returned by this function indicates the coordenates of the
 * first box's vertex of the table (top, left side)
 */
static Vector2 Get_table_box_starting_position(void)
{
    Vector2 line_sep = Get_table_separator_starting_position();

    line_sep.x -= BOX_WIDTH;

    return line_sep;
}

void draw_table() {
    //Vector2 start = {.x = 600, .y = 200};
    Vector2 start = Get_table_separator_starting_position();
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
            create_button(button.x, button.y, button.width, button.height, NULL);
            DrawRectangle((int)button.x, (int)button.y, (int)button.width, (int)button.height, RED_LOW_OPACITY);
        }

        button.x -= BOX_WIDTH * 3;
        button.y += BOX_HEIGHT;
    }
}

int initialize_buttons(void) {
    buttons = malloc(sizeof(*buttons) * BOX_AMOUNT);

    if (buttons == NULL) return EXIT_FAILURE;

    button_textures = malloc(sizeof(*button_textures) * BOX_AMOUNT);

    if (button_textures == NULL) return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

void delete_buttons(void) {
    for (size_t i = 0; i < BOX_AMOUNT; i++)
    {
        free(buttons[i]);
    }

    free(buttons);
    buttons = NULL;

    free(button_textures);
    button_textures = NULL;
}

int create_button(const float x, const float y, const float width, const float height, const Texture2D* texture)
{
    if (buttons_counter >= BOX_AMOUNT)
        return EXIT_FAILURE;

    Rectangle* new_button = malloc(sizeof(Rectangle));

    if (new_button == NULL)
        return EXIT_FAILURE;

    new_button->x = x;
    new_button->y = y;
    new_button->width = width;
    new_button->height = height;

    buttons[buttons_counter] = new_button;
    buttons_counter++;

    return EXIT_SUCCESS;
}

bool is_clicking_box(const Vector2 mouse_pos)
{
    Vector2 box_coord = Get_table_box_starting_position();

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++, box_coord.x += BOX_WIDTH)
        {
            // Check if mouse_pos is between a range in x-y axis.
            if (
                box_coord.x <= mouse_pos.x && mouse_pos.x <= box_coord.x + BOX_WIDTH &&
                box_coord.y <= mouse_pos.y && mouse_pos.y <= box_coord.y + BOX_HEIGHT
                ) return true;
        }

        box_coord.x -= BOX_WIDTH * 3;
        box_coord.y += BOX_HEIGHT;
    }

    return false;
}