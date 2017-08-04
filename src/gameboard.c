#include "gameboard.h"

/**
 * Initialise the game board to be consistent with the screenshot provided
 * in your assignment specification. 
 *
 * All squares should be initialised to be blank other than the four
 * squares in the middle of the board. In that case they are initialised to 
 * appropriate colored tokens.
 **/
void initBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH]) {
    for (int i = 0; i < BOARD_WIDTH; i++) {
        for (int ii = 0; ii < BOARD_HEIGHT; ii++) {
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
    puts("     1   2   3   4   5   6   7   8");
    puts("====================================");

    for (int i = 0; i < BOARD_WIDTH; i++) {

        printf(" %d |", i+1);

        for (int ii = 0; ii < BOARD_HEIGHT; ii++) {
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
