#include "turn.h"

Player *change_player_turn(Player *player1, Player *player2) {
    static int player_turn = 0;
    Player *actual_player;

    switch (player_turn)
    {
    case 0:
        player_turn = 1;
        actual_player = player1;
        break;
    case 1:
        player_turn = 2;
        actual_player = player2;
        break;
    case 2:
        player_turn = 1;
        actual_player = player1;
        break;
    }

    return actual_player;
}
