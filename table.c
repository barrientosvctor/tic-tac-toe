#include "table.h"
#include <stdbool.h>
#include <stdio.h>

// TODO: put x-y numbers in each box
// TODO: check if a box has been filled before
// TODO: function to format the player's plays
void print_table(int (*table)[3][3]) {
  printf("\n");
  printf(" %d | %d | %d\n", (*table)[0][0], (*table)[0][1], (*table)[0][2]);
  puts("-----------");
  printf(" %d | %d | %d\n", (*table)[1][0], (*table)[1][1], (*table)[1][2]);
  puts("-----------");
  printf(" %d | %d | %d\n", (*table)[2][0], (*table)[2][1], (*table)[2][2]);
  printf("\n");
}

void check_winner(Player *player1, Player *player2, int (*table)[3][3]) {
  if (is_winner(player1, table))
    player1->is_winner = true;
  else if (is_winner(player2, table))
    player2->is_winner = true;
}

bool is_filled(int (*table)[3][3]) {
  for (int vertical = 0; vertical < 3; vertical++) {
    for (int horizontal = 0; horizontal < 3; horizontal++) {
      if ((*table)[vertical][horizontal] == 0)
        return false;
    }
  }

  return true;
}
