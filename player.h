#pragma once

#include <stdbool.h>

typedef struct player_t Player;

Player *create_player(const int);
void free_player(Player *);
void play(Player *, const int, const int, int (*)[3][3]);
bool is_table_winner(Player *, const int (*)[3][3]);
