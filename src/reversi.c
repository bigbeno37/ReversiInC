#include "reversi.h"

int main()
{
    Player player1;
    Player player2;

    Player *winner = playGame(&player1, &player2);
    
    if (winner == NULL) {
        puts("The game was a tie!");
    } else {
        printf("Congratulations %s, you won with %d points!\n", winner->name, winner->score); 
    }
    
    puts("");
    puts("Goodbye. ");

    return EXIT_SUCCESS;
}
