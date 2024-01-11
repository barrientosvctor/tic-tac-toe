#include "player.h"
#include <stdlib.h>

typedef struct player_t {
  int turn_id;
  int plays;
  bool is_winner;
} Player;

Player *create_player(const int id) {
  Player *p = malloc(sizeof(Player));

  p->is_winner = false, p->plays = 0, p->turn_id = id;

  return p;
}

void free_player(Player *player) {
  free(player);
  player = NULL;
}

static Player *change_player_turn(Player *player1, Player *player2) {
  static int player_turn = 0;
  Player *actual_player;

  if (0 == player_turn) {
    player_turn = player1->turn_id;
    actual_player = player1;
  } else if (player_turn == player1->turn_id) {
    player_turn = player2->turn_id;
    actual_player = player2;
  } else if (player_turn == player2->turn_id) {
    player_turn = player1->turn_id;
    actual_player = player1;
  }

  return actual_player;
}

void play(Player *player1, Player *player2, const int pos_x, const int pos_y,
          int (*table)[3][3]) {
  Player *actual = change_player_turn(player1, player2);

  (*table)[pos_y][pos_x] = actual->turn_id;
  actual->plays++;
}

bool is_player_winner(Player *player) { return player->is_winner == true; }

bool is_table_winner(Player *player, const int (*table)[3][3]) {
  if (
      // all posible vertical wins
      (((*table)[0][0] == player->turn_id &&
        (*table)[1][0] == player->turn_id &&
        (*table)[2][0] == player->turn_id) ||
       ((*table)[0][1] == player->turn_id &&
        (*table)[1][1] == player->turn_id &&
        (*table)[2][1] == player->turn_id) ||
       ((*table)[0][2] == player->turn_id &&
        (*table)[1][2] == player->turn_id &&
        (*table)[2][2] == player->turn_id)) ||
      // all posible horizontal wins
      (((*table)[0][0] == player->turn_id &&
        (*table)[0][1] == player->turn_id &&
        (*table)[0][2] == player->turn_id) ||
       ((*table)[1][0] == player->turn_id &&
        (*table)[1][1] == player->turn_id &&
        (*table)[1][2] == player->turn_id) ||
       ((*table)[2][0] == player->turn_id &&
        (*table)[2][1] == player->turn_id &&
        (*table)[2][2] == player->turn_id)) ||
      // all posible diagonal wins
      (((*table)[0][0] == player->turn_id &&
        (*table)[1][1] == player->turn_id &&
        (*table)[2][2] == player->turn_id) ||
       ((*table)[0][2] == player->turn_id &&
        (*table)[1][1] == player->turn_id &&
        (*table)[2][0] == player->turn_id)))
    return true;

  return false;
}

void check_winner(Player *player1, Player *player2, const int (*table)[3][3]) {
  if (is_table_winner(player1, table))
    player1->is_winner = true;
  else if (is_table_winner(player2, table))
    player2->is_winner = true;
}
