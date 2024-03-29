#include "table.h"
#include <stdbool.h>
#include <stdio.h>

void print_table(const int (*table)[3][3])
{
    printf("\n");
    puts("     X1  X2  X3");
    printf("Y1 | %c | %c | %c\n", format_box((*table)[0][0]),
           format_box((*table)[0][1]), format_box((*table)[0][2]));
    puts("---------------");
    printf("Y2 | %c | %c | %c\n", format_box((*table)[1][0]),
           format_box((*table)[1][1]), format_box((*table)[1][2]));
    puts("---------------");
    printf("Y3 | %c | %c | %c\n", format_box((*table)[2][0]),
           format_box((*table)[2][1]), format_box((*table)[2][2]));
    printf("\n");
}

void check_winner(Player *player1, Player *player2, const int (*table)[3][3])
{
    if (is_winner(player1, table))
        player1->is_winner = true;
    else if (is_winner(player2, table))
        player2->is_winner = true;
}

bool is_filled(const int (*table)[3][3])
{
    for (int vertical = 0; vertical < 3; vertical++)
    {
        for (int horizontal = 0; horizontal < 3; horizontal++)
        {
            if ((*table)[vertical][horizontal] == 0)
                return false;
        }
    }

    return true;
}

bool is_box_filled(const int (*table)[3][3], const int pos_x, const int pos_y)
{
    return (*table)[pos_y][pos_x] != 0;
}

const char format_box(const int box_number)
{
    switch (box_number)
    {
    case 1:
        return 'X';
    case 2:
        return 'O';
    default:
        return ' ';
    }
}

bool has_reached_table_size(const int min_table_size_x, const int max_table_size_x, const int min_table_size_y, const int max_table_size_y, const int pos_x, const int pos_y)
{
    return pos_x > max_table_size_x || pos_y > max_table_size_y || pos_x <= min_table_size_x || pos_y <= min_table_size_y;
}
