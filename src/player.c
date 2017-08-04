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
    char name[NAMELEN + 2];

    printf("Please enter your name: ");

    Boolean correctInput = FALSE;

    while (!correctInput) {

        correctInput = TRUE;

        if (!fgets(name, NAMELEN+2, stdin)) {
            printf("You need to enter a name: ");
            correctInput = FALSE;
        } else {
            if (name[NAMELEN] == 0) {
                readRestOfLine();

                puts(name);

                printf("Name too long! Enter a new name! ");

                correctInput = FALSE;
            }
        }

        puts("");
    }


}

void initSecondPlayer(Player * player, Cell token)
{ }
