#include "gameboard.h"

void printPlayerDetails(Player *player) {
    if (player->token == RED) {
        printf("Name: %s\t Score: %d\tToken Color: " COLOR_RED "O" COLOR_RESET "\n", player->name, player->score);
    } else {
        printf("Name: %s\t Score: %d\tToken Color: " COLOR_CYAN "O" COLOR_RESET "\n", player->name, player->score);
    }
}


/**
 * Initialise the game board to be consistent with the screenshot provided
 * in your assignment specification. 
 *
 * All squares should be initialised to be blank other than the four
 * squares in the middle of the board. In that case they are initialised to 
 * appropriate colored tokens.
 **/
void initBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH]) {

    int i, ii;
    for (i = 0; i < BOARD_WIDTH; i++) {
        for (ii = 0; ii < BOARD_HEIGHT; ii++) {
            board[i][ii] = BLANK;
        }
    }

    board[3][3] = RED;
    board[3][4] = CYAN;
    board[4][3] = CYAN;
    board[4][4] = RED;
}

/**
 * Display the board as specified in the assignment specification. You should 
 * make every effort to create a board consistent with the screenshots in the 
 * assignment specification.
 **/
void displayBoard(
    Cell board[BOARD_HEIGHT][BOARD_WIDTH], Player * first, Player * second)
{
    int i, ii;
    
    puts("================================================================================");
    puts("Player One's Details");
    puts("--------------------");

    printPlayerDetails(first);

    puts("--------------------------------------------------------------------------------");
    puts("Player Two's Details");
    puts("--------------------");

    printPlayerDetails(second);

    puts("--------------------------------------------------------------------------------");

    puts("\t 1   2   3   4   5   6   7   8");
    puts("====================================");

    for (i = 0; i < BOARD_WIDTH; i++) {

        printf(" %d |", i+1);

        for (ii = 0; ii < BOARD_HEIGHT; ii++) {
            if (board[i][ii] != BLANK) {

                if (board[i][ii] == RED) {
                    printf(COLOR_RED " O" COLOR_RESET " |" COLOR_RESET);
                } else {
                    printf(COLOR_CYAN " O" COLOR_RESET " |" COLOR_RESET);
                }

            } else {
                printf("   |");
            }
        }

        puts("");
        puts("------------------------------------");
    }
}


