#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "player.h"
#include "table.h"
#include "turn.h"

int main(void) {
  Player player1 = {.plays = 0, .turn_id = 1, .is_winner = false},
         player2 = {.plays = 0, .turn_id = 2, .is_winner = false};

  int pos_x, pos_y;
  int game_table[TABLE_SIZE_Y][TABLE_SIZE_X] = {
      {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

  while ((!player1.is_winner && !player2.is_winner) &&
         !is_filled(&game_table)) {
    print_table(&game_table);

    printf("Type an X position in the table: ");
    scanf("%d", &pos_x);

    printf("Type an Y position in the table: ");
    scanf("%d", &pos_y);

    while (has_reached_table_size(TABLE_SIZE_X - 1, TABLE_SIZE_Y - 1, pos_x,
                                  pos_y)) {
      print_table(&game_table);

      printf("WARNING: The positions X%d, Y%d is out of the table size, type "
             "another position!\n",
             pos_x, pos_y);
      printf("Type an X position in the table: ");
      scanf("%d", &pos_x);

      printf("Type an Y position in the table: ");
      scanf("%d", &pos_y);
    }

    while (is_box_filled(&game_table, pos_x, pos_y)) {
      print_table(&game_table);

      printf("WARNING: The box X%d, Y%d is filled, choose another box!\n",
             pos_x, pos_y);
      printf("Type an X position in the table: ");
      scanf("%d", &pos_x);

      printf("Type an Y position in the table: ");
      scanf("%d", &pos_y);
    }

    play(change_player_turn(&player1, &player2), pos_x, pos_y, &game_table);

    check_winner(&player1, &player2, &game_table);
  }

  puts("-------------");

  if (is_filled(&game_table)) {
    if (player1.is_winner || player2.is_winner)
      printf("Player %d wins!\n",
             player1.is_winner ? player1.turn_id : player2.turn_id);
    else
      puts("The table is full. No winners!");
  } else {
    if (player1.is_winner || player2.is_winner)
      printf("Player %d wins!\n",
             player1.is_winner ? player1.turn_id : player2.turn_id);
  }

  print_table(&game_table);

  return EXIT_SUCCESS;
}
