#include "reversi.h"

int main()
{
    char input[2];
    Cell board[BOARD_HEIGHT][BOARD_WIDTH];

    Player player1;
    Player player2;

    playGame(&player1, &player2);

    return EXIT_SUCCESS;
}
