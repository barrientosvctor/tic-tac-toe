#include <raylib.h>
#include <stdlib.h>

#include "table.h"
#include "button.h"

static const unsigned short width = 1280, height = 720;

int main(void)
{
	if (initialize_buttons() == EXIT_FAILURE)
		return EXIT_FAILURE;

	InitWindow(width, height, "Tic Tac Toe");

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawText("Tic Tac Toe Game", (width / 2 - 50), 5, 20, BLACK);
		draw_table();
		EndDrawing();
	}

	delete_buttons();
	CloseWindow();

	return 0;
}
