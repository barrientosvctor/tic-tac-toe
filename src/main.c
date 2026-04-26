#include <stdio.h>
#include <stdlib.h>

#include <raylib.h>

#include "table.h"

static const unsigned short width = 1280, height = 720;

int main(void)
{
	InitWindow(width, height, "Tic Tac Toe");

	if (initialize_buttons() == EXIT_FAILURE)
		return EXIT_FAILURE;

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawText("Tic Tac Toe Game", (width / 2 - 50), 5, 20, BLACK);
		draw_table();

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			Vector2 mouse_pos = GetMousePosition();

			if (is_clicking_box(mouse_pos))
			{
				puts("Clicked box!");
			}
		}
		EndDrawing();
	}

	delete_buttons();
	CloseWindow();

	return 0;
}
