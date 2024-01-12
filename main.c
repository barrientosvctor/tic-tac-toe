#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "player.h"
#include "table.h"

int main(void) {
  Player *player1 = create_player(1), *player2 = create_player(2);

  int pos_x, pos_y;
  int game_table[TABLE_SIZE_Y][TABLE_SIZE_X] = {
      {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

  while ((!is_player_winner(player1) && !is_player_winner(player2)) &&
         !is_filled(&game_table)) {
    print_table(&game_table);

    printf("Type an X position in the table: ");
    scanf("%d", &pos_x);

    printf("Type an Y position in the table: ");
    scanf("%d", &pos_y);

    while (has_reached_table_size(TABLE_SIZE_X, TABLE_SIZE_Y, pos_x, pos_y)) {
      print_table(&game_table);

      printf("WARNING: The positions X%d, Y%d is out of the table size, type "
             "another position!\n",
             pos_x, pos_y);
      printf("Type an X position in the table: ");
      scanf("%d", &pos_x);

      printf("Type an Y position in the table: ");
      scanf("%d", &pos_y);
    }

    while (is_box_filled(&game_table, pos_x - 1, pos_y - 1)) {
      print_table(&game_table);

      printf("WARNING: The box X%d, Y%d is filled, choose another box!\n",
             pos_x, pos_y);
      printf("Type an X position in the table: ");
      scanf("%d", &pos_x);

      printf("Type an Y position in the table: ");
      scanf("%d", &pos_y);
    }

    play(player1, player2, pos_x - 1, pos_y - 1, &game_table);

    check_winner(player1, player2, &game_table);
  }

  puts("-------------------------------");

  if (is_filled(&game_table)) {
    if (is_player_winner(player1) || is_player_winner(player2))
      printf("Player %d wins!\n", is_player_winner(player1) ? 1 : 2);
    else
      puts("The table is full. No winners!");
  } else {
    if (is_player_winner(player1) || is_player_winner(player2))
      printf("Player %d wins!\n", is_player_winner(player1) ? 1 : 2);
  }

  print_table(&game_table);

  free_player(player1);
  free_player(player2);

  return EXIT_SUCCESS;
}
