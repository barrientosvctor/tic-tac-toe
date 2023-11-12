#include <stdio.h>

#include "table.h"

int main(void) {
    int player_one = 0, player_two = 0;
    int game_table[3][3] = {
        { 0, 0, 0 },
        { 0, 0, 0 },
        { 0, 0, 0 }
    };

    coso();
    coso();
    coso();

    // while (player_one != 1 && player_two != 1) {

    // }

    print_table(&game_table);
    return 0;
}
