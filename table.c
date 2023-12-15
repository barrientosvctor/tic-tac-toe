#include "table.h"
#include <stdbool.h>
#include <stdio.h>

// TODO: put x-y numbers in each box
// TODO: check if a box has been filled before
// TODO: check if the x-y positions given by the user are greater than the table
// size
void print_table(int (*table)[3][3]) {
  printf("\n");
  printf(" %c | %c | %c\n", format_box((*table)[0][0]),
         format_box((*table)[0][1]), format_box((*table)[0][2]));
  puts("-----------");
  printf(" %c | %c | %c\n", format_box((*table)[1][0]),
         format_box((*table)[1][1]), format_box((*table)[1][2]));
  puts("-----------");
  printf(" %c | %c | %c\n", format_box((*table)[2][0]),
         format_box((*table)[2][1]), format_box((*table)[2][2]));
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

bool is_box_filled(int (*table)[3][3], int pos_x, int pos_y) {
  return (*table)[pos_y][pos_x] != 0;
}

const char format_box(int box_number) {
  switch (box_number) {
  case 1:
    return 'X';
  case 2:
    return 'O';
  default:
    return ' ';
  }
}

bool has_reached_table_size(const int table_size_x, const int table_size_y,
                            int pos_x, int pos_y) {
  return pos_x > table_size_x || pos_y > table_size_y;
}
