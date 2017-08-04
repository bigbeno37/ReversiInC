#include "player.h"

/**
 * These two functions initialise the player structure at the beginning of the
 * game. In both cases, you should initialise the whole structure to known safe
 * values and then prompt the user for their name. In the initFirstPlayer()
 * function you should then select a color at random for this player using the
 * rand() function. This token should be assigned to the first player's token.
 * In initSecondPlayer() you should just test the value of token and assign the
 * opposite color to the second player.
 * 
 * Note that an empty name is not valid and the user should be re-prompted.
 **/
void initFirstPlayer(Player * player)
{
    // Create a new char array of size 20, with 1 extra for newline support
    static char name[NAMELEN + 1] = "";

    printf("Player 1, enter your name: ");
    getUserInput(name);

    // Get the current time and set it as the seed for rand()
    time_t t;
    srand( (unsigned) time(&t));

    strcpy(player->name, name);
    player->score = 0;
    // Get a random number between 0 and 1; if 0, the player is RED, if 1, the player is CYAN
    player->token = (rand() % 2 == 0) ? RED : CYAN;
}

void initSecondPlayer(Player * player, Cell token)
{
    static char name[NAMELEN + 1] = "";

    printf("Player 2, enter your name: ");
    getUserInput(name);

    time_t t;
    srand( (unsigned) time(&t));

    strcpy(player->name, name);
    player->score = 0;
    // Choose the opposite token from the one passed in
    player->token = (token == RED) ? CYAN : RED;
}
