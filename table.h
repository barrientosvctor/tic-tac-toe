#pragma once

#define TABLE_SIZE_X 3
#define TABLE_SIZE_Y TABLE_SIZE_X

#include <stdbool.h>

void print_table(const int (*)[3][3]);
bool is_filled(const int (*)[3][3]);
bool is_box_filled(const int (*)[3][3], const int, const int);
const char format_box(const int);
bool has_reached_table_size(const int, const int, const int, const int);
