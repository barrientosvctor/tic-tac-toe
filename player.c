#include "player.h"
#include <stdlib.h>

Player *change_player_turn(Player *player1, Player *player2) {
  static unsigned short counter = 0;
  Player *actual_player = NULL;

  switch (counter) {
  case 0:
    actual_player = player1;
    counter = 1;
    break;
  case 1:
    actual_player = player2;
    counter = 2;
    break;
  case 2:
    actual_player = player1;
    counter = 1;
  default:
    actual_player = NULL;
    counter = 0;
    break;
  }

  return actual_player;
}
void play(Player *player, const int pos_x, const int pos_y,
          int (*table)[3][3]) {
  (*table)[pos_y][pos_x] = player->turn_id;
  player->plays++;
}

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
