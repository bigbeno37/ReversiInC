#include "reversi.h"

int main()
{
    Player player1;
    Player player2;

    playGame(&player1, &player2);
    
    puts("");
    puts("Goodbye. ");

    return EXIT_SUCCESS;
}
