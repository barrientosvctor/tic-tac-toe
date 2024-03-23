#pragma once

#define MAX_TABLE_SIZE_X 3
#define MAX_TABLE_SIZE_Y MAX_TABLE_SIZE_X
#define MIN_TABLE_SIZE_X 0
#define MIN_TABLE_SIZE_Y 0

#include "player.h"
#include <stdbool.h>

void print_table(const int (*)[3][3]);
void check_winner(Player *, Player *, const int (*)[3][3]);
bool is_filled(const int (*)[3][3]);
bool is_box_filled(const int (*)[3][3], const int, const int);
const char format_box(const int);
bool has_reached_table_size(const int min_x, const int max_x, const int min_y, const int max_y, const int pos_x, const int pos_y);
