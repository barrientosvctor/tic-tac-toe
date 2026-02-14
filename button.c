#include <stdlib.h>
#include <string.h>

#include "button.h"

#define BUTTON_AMOUNT 9

static Rectangle** buttons = NULL;
static Texture2D* button_textures = NULL;
static int buttons_counter = 0;

int initialize_buttons(void) {
	buttons = malloc(sizeof(*buttons) * BUTTON_AMOUNT);

	if (buttons == NULL) return EXIT_FAILURE;

	button_textures = malloc(sizeof(*button_textures) * BUTTON_AMOUNT);

	if (button_textures == NULL) return EXIT_FAILURE;

	return EXIT_SUCCESS;
}

void delete_buttons(void) {
	for (size_t i = 0; i < BUTTON_AMOUNT; i++)
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
	if (buttons_counter > BUTTON_AMOUNT - 1)
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