#include "table.h"
#include <stdio.h>
#include <stdbool.h>

// TODO: put x-y numbers in each box
//TODO: check if a box has been filled before
// TODO: check when entire table is filled
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
