#pragma once

#include <stdbool.h>

typedef struct player_t Player;

void play(Player *, const int, const int, int (*)[3][3]);

bool is_winner(Player *, const int (*)[3][3]);
