#pragma once

#include "player.h"
#include <stdbool.h>

void print_table(int (*)[3][3]);
void check_winner(Player *, Player *, int (*)[3][3]);
bool is_filled(int (*)[3][3]);
char format_box(int);
