#include "game.h"

/**
 * The heart of the game itself. You should do ALL initialisation required
 * for the game in here or call function required for that purpose. For example
 * both players should be initialised from here, you should seed the random
 * number generator, etc...
 * 
 * Next, you should set the initial player - the initial player is the player
 * whose token was set to RED.
 * 
 * Next you will need to manage the game loop in here. In each loop of the
 * game, you should display the game board, including player scores
 * display whose turn it is, etc... in the format from the assignment
 * specification. Finally at the end of each turn you will calculate the score
 * for each player and store it and then you will need to swap the current player
 * and other player using the swapPlayer() function.
 * 
 * A game will end when either player presses enter on a newline.
 * 
 * When you detect a request to end the game you should do a final calculation
 * of the scores for the two players and return the player with the highest
 * score - if its a draw return NULL.
 **/
Player * playGame(Player * first, Player * second)
{
    return NULL;
}

/**
 * Prompts the user for a comma-separate pair of coordinates for a move in the
 * game. Each move, if valid, must capture at least one enemy piece by
 * surrounding a sequence of one or more enemy pieces with two pieces of our
 * own: one being the new piece to be placed and the other a piece already
 * on the board. This function then validates that a valid move has been entered
 * and calls the applyMove() function to do the actual work of capturing pieces.
 * 
 * FALSE is returned if an empty line is entered (to end the game), otherwise
 * the prompt will continue until a valid move is entered and then TRUE is returned.
 **/
Boolean makeMove(Player * player, Cell board[BOARD_HEIGHT][BOARD_WIDTH])
{
    return FALSE;
}

/**
 * Applys the move requested by the user to the game board.
 * 
 * It iterates over all the directions from the coordinate specified to see
 * whether there are any pieces that can be captured.
 * 
 * If there are no pieces that can be captured in any direction it is an
 * invalid move and FALSE is returned (with no changes to the board occurring),
 * otherwise TRUE is returned, the pieces are captured and the token is
 * placed on the board.
 **/
Boolean applyMove(Cell board[BOARD_HEIGHT][BOARD_WIDTH], int y, int x, Cell token)
{
    return FALSE;
}

/**
 * Simply counts how many locations contain the token specified on board.
 **/
unsigned gameScore(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Cell token)
{
    return 0;
}

/**
 * Swaps the two player pointers so that first points to second and vice versa.
 **/
void swapPlayers(Player ** first, Player ** second)
{ }
