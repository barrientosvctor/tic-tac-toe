#include "player.h"

void increment_play(Player *player) { player->plays++; }

void play(Player *player, const int pos_x, const int pos_y,
          int (*table)[3][3]) {
  (*table)[pos_y][pos_x] = player->turn_id;
  increment_play(player);
}

bool is_winner(Player *player, int (*table)[3][3]) {
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
