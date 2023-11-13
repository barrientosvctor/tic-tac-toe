#pragma once

#include "player.h"

void print_table(int (*table)[3][3]);
void check_winner(Player *, Player *, int (*)[3][3]);
