#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "player.h"
#include "table.h"
#include "turn.h"

int main(void) {
  Player player1 = {.plays = 0, .turn_id = 1, .is_winner = false};
  Player player2 = {.plays = 0, .turn_id = 2, .is_winner = false};

  int pos_x, pos_y;
  int game_table[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

  while (!player1.is_winner && !player2.is_winner) {
    print_table(&game_table);

    printf("Type an X position in the table: ");
    scanf("%d", &pos_x);

    printf("Type an Y position in the table: ");
    scanf("%d", &pos_y);

    play(change_player_turn(&player1, &player2), pos_x, pos_y, &game_table);

    check_winner(&player1, &player2, &game_table);
  }

  printf("player 1 wins? %d\n", player1.is_winner);
  printf("player 2 wins? %d\n", player2.is_winner);

  return EXIT_SUCCESS;
}
