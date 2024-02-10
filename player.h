#pragma once

#include <stdbool.h>

typedef struct player_t {
  int turn_id;
  int plays;
  bool is_winner;
} Player;

Player *change_player_turn(Player *, Player *);
void play(Player *, const int, const int, int (*)[3][3]);
bool is_table_winner(Player *, const int (*)[3][3]);
void check_winner(Player *, Player *, const int (*)[3][3]);
