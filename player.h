#pragma once

#include <stdbool.h>

typedef struct player_t
{
    int turn_id;
    int plays;
    bool is_winner;
} Player;

void increment_play(Player *);

void play(Player *, const int, const int, int (*)[3][3]);

bool is_winner(Player *, int (*)[3][3]);
