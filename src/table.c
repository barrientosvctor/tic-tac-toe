#include <stdlib.h>

#include <raylib.h>

#include "table.h"
#include "utils.h"

#define BOX_WIDTH 100
#define BOX_HEIGHT 100
#define HORIZONTAL_BOX_AMOUNT 3
#define VERTICAL_BOX_AMOUNT 3
#define HORIZONTAL_BOX_SEPARATOR (VERTICAL_BOX_AMOUNT - 1)
#define VERTICAL_BOX_SEPARATOR (HORIZONTAL_BOX_AMOUNT - 1)
#define BOX_AMOUNT (HORIZONTAL_BOX_AMOUNT * VERTICAL_BOX_AMOUNT)

struct box
{
	Texture2D texture;
	Rectangle button;
	size_t id;
};

static struct box **buttons = NULL;
static size_t buttons_counter = 0;

/*
 * Gets the starting position of the table's separator.
 *
 * NOTE: 2D vector returned by this function indicates the coordenates of the
 * first line separator of the table (top, left side, between first and second
 * box)
 */
static Vector2 Get_table_separator_starting_position(void)
{
	return (Vector2){ GetRenderWidth() / 2.0f - BOX_WIDTH / 2.0f,
					  GetRenderHeight() / 2.0f - BOX_HEIGHT / 2.0f };
}

/*
 * Gets the starting position of the first table box.
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

static int Create_buttons(void)
{
	Vector2 pos = Get_table_box_starting_position();

	for (size_t i = 0; i < VERTICAL_BOX_AMOUNT; i++)
	{
		for (size_t j = 0; j < HORIZONTAL_BOX_AMOUNT; j++, pos.x += BOX_WIDTH)
		{
			if (create_button(pos.x, pos.y, BOX_WIDTH, BOX_HEIGHT) ==
				EXIT_FAILURE)
				return EXIT_FAILURE;
		}

		pos.x -= BOX_WIDTH * HORIZONTAL_BOX_AMOUNT;
		pos.y += BOX_HEIGHT;
	}

	return EXIT_SUCCESS;
}

static struct box *Get_box(const size_t id)
{
	for (size_t i = 0; i < BOX_AMOUNT; i++)
	{
		struct box *target = buttons[i];

		if (target->id == id)
			return target;
	}

	return NULL;
}

void draw_table()
{
	Vector2 start = Get_table_separator_starting_position();
	Vector2 end = { .x = start.x, .y = start.y + BOX_HEIGHT * 3 };
	struct box *box = NULL;

	// Vertical lines rendering
	for (int i = 0; i < VERTICAL_BOX_SEPARATOR;
		 ++i, start.x += BOX_WIDTH, end.x += BOX_WIDTH)
	{
		DrawLineV(start, end, BLACK);
	}

	// Sets the x coordinate of the start
	// vector to the beginning of the
	// first box at the up-left side.
	start.x -= BOX_WIDTH * HORIZONTAL_BOX_AMOUNT;

	// Sets the y coordinate of the start vector to the
	// bottom of the first box.
	start.y += BOX_HEIGHT;
	end.y = start.y;

	// Horizontal lines rendering
	for (int i = 0; i < HORIZONTAL_BOX_SEPARATOR;
		 ++i, start.y += BOX_HEIGHT, end.y += BOX_HEIGHT)
	{
		DrawLineV(start, end, BLACK);
	}

	// Drawing buttons
	size_t id = 0;
	for (int i = 0; i < VERTICAL_BOX_AMOUNT; i++)
	{
		for (int j = 0; j < HORIZONTAL_BOX_AMOUNT; j++)
		{
			box = Get_box(id++);
			DrawRectangle((int)box->button.x, (int)box->button.y,
						  (int)box->button.width, (int)box->button.height,
						  RED_LOW_OPACITY);
		}
	}
}

int initialize_buttons(void)
{
	buttons = malloc(sizeof(*buttons) * BOX_AMOUNT);

	if (buttons == NULL)
		return EXIT_FAILURE;

	int code = Create_buttons();

	if (code == EXIT_FAILURE)
	{
		free_buttons();
	}

	return code;
}

void free_buttons(void)
{
	for (size_t i = 0; i < BOX_AMOUNT; i++)
	{
		free(buttons[i]);
	}

	free(buttons);
	buttons = NULL;
}

int create_button(const float x, const float y, const float width,
				  const float height)
{
	if (buttons_counter >= BOX_AMOUNT)
		return EXIT_FAILURE;

	struct box *new_button = malloc(sizeof *new_button);

	if (new_button == NULL)
		return EXIT_FAILURE;

	new_button->id = buttons_counter;
	new_button->texture = (Texture2D){ .id = (unsigned int)buttons_counter,
									   .width = BOX_WIDTH,
									   .height = BOX_HEIGHT };
	new_button->button.x = x;
	new_button->button.y = y;
	new_button->button.width = BOX_WIDTH;
	new_button->button.height = BOX_HEIGHT;

	buttons[buttons_counter++] = new_button;

	return EXIT_SUCCESS;
}

bool is_clicking_box(const Vector2 mouse_pos)
{
	const struct box *box;
	size_t id = 0;

	for (size_t i = 0; i < VERTICAL_BOX_AMOUNT; i++)
	{
		for (size_t j = 0; j < HORIZONTAL_BOX_AMOUNT; j++)
		{
			box = Get_box(id++);
			// Check if mouse_pos is between a range in x-y axis.
			if (box->button.x <= mouse_pos.x &&
				mouse_pos.x <= box->button.x + box->button.width &&
				box->button.y <= mouse_pos.y &&
				mouse_pos.y <= box->button.y + box->button.height)
				return true;
		}
	}

	return false;
}