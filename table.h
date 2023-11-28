#pragma once

#define TABLE_SIZE_X 3
#define TABLE_SIZE_Y TABLE_SIZE_X

#include "player.h"
#include <stdbool.h>

void print_table(int (*)[3][3]);
void check_winner(Player *, Player *, int (*)[3][3]);
bool is_filled(int (*)[3][3]);
bool is_box_filled(int (*)[3][3], int, int);
char format_box(int);
bool has_reached_table_size(const int, const int, int, int);
