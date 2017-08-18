#include "reversi.h"

int main()
{
    while (TRUE) {
        Player player1;
        Player player2;

        Player *winner = playGame(&player1, &player2);

        puts(EMPTY_STRING);

        if (winner == NULL) {
            puts("The game was a tie!\n\n");
        } else {
            printf("Congratulations %s, you won with %d points!\n\n", winner->name, winner->score);
        }
    }

    return EXIT_SUCCESS;
}
