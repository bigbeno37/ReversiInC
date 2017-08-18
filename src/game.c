#include "game.h"

Cell oppositeOf(Cell tokenToFlip);

void flipPieces(Position pos, Direction dir, Cell token, Cell board[8][8]) ;

Boolean isLegalMove(Position pos, Direction dir,
                    Cell token, Cell board[8][8]) ;

void updateScores(Cell board[8][8], Player *firstPlayer, Player *secondPlayer);

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
    Cell board[BOARD_WIDTH][BOARD_HEIGHT];
    long int choice = 0;
    Boolean validChoice = FALSE;
    Player *currentPlayer, *opponent;
    
    /* Seed the random number generator using the current time */
    time_t t;
    srand( (unsigned) time(&t));

    displayWelcome();
    
    choice = getUserChoice();

    while (!validChoice) {

        validChoice = TRUE;

        if (choice == 1) {
            /* Continue below */
        } else if (choice == 2) {
            puts(EMPTY_STRING);
            puts("Goodbye. ");

            exit(0);
        } else {

            validChoice = FALSE;

            puts("\nNot a valid choice!");
            printf("Enter a choice: ");

            choice = getUserChoice();
        }
    }

    initFirstPlayer(first);
    initSecondPlayer(second, first->token);
    
    /* Assign the current player and opponent. Whoever has the RED colour goes first*/
    currentPlayer = (first->token == RED) ? first : second;
    opponent = (first->token == RED) ? second : first;

    initBoard(board);
    updateScores(board, first, second);
    displayBoard(board, first, second);

    /* The main loop; if the move made was successful, swap players and play the next round */
    while (makeMove(currentPlayer, board)) {
        updateScores(board, first, second);
        swapPlayers(&currentPlayer, &opponent);
        displayBoard(board, first, second);
    }


    /* If the two player's scores are tied, return NULL */
    if ( first->score == second->score ) {
        return NULL;
    }

    /* Otherwise return whoever scored higher */
    return ( first->score > second->score ) ? first : second;

}

/* Updates the scores of both players */
void updateScores(Cell board[8][8], Player *firstPlayer, Player *secondPlayer) {
    firstPlayer->score  = gameScore(board, firstPlayer->token);
    secondPlayer->score = gameScore(board, secondPlayer->token);
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
    char buffer[3 + EXTRA_SPACES] = EMPTY_STRING, *position;
    long x = 0, y = 0;
    Boolean validInput = FALSE;
    
    printf("It is %s's turn.\n", player->name);
    printf("Please enter x and y coordinates separated by a comma for the piece you wish to place: ");

    while (!validInput) {
        validInput = TRUE;
        
        fgets(buffer, 3 + EXTRA_SPACES, stdin);

        if (!strchr(buffer, '\n')) {
            printf("Buffer overflow! Enter a position separated by a comma: ");
            readRestOfLine();

            validInput = FALSE;

            continue;

        }

        if (buffer[0] == '\n') {
            return FALSE;
        }

        /* Get the first token of the buffer */
        position = strtok(buffer, ",");
        /* Validate that the token can be converted to an int */
        if (position != NULL) {
            x = strtol(position, NULL, 10);
        }

        /* Get the second token of the buffer */
        position = strtok(NULL, ",");
        /* Validate that the token can be converted to an int */
        if (position != NULL) {
            y = strtol(position, NULL, 10);
        }

        /* If the converted values aren't between 1 and 8, return into the loop */
        if (!(1 <= x && x <= 8) || !(1 <= y && y <= 8)) {
            validInput = FALSE;

            printf("Invalid input! Enter a position separated by a comma: ");
            continue;
        }
        
        /* If the position specified is against the rules, return into the loop */
        if (!applyMove(board, (int)(y-1), (int)(x-1), player->token)) {
            validInput = FALSE;

            printf("Invalid move! Enter a valid move: ");
            continue;
        }
    }
    
    return TRUE;
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
    int i, ii;
    Boolean legalMove = FALSE;
    Position pos;
    Direction dir;

    /* Board goes y then x in [][] eg [1][2] is 2nd row 3rd column */

    /* If move is valid it must not be on an occupied space */
    if (board[y][x] != BLANK) {
        return FALSE;
    }


    /* Check the 8 directions around the pieces */
    for (i = -1; i <= 1; i++) {
        for (ii = -1; ii <= 1; ii++) {

            /* Check for out of bounds */
            if ( !((y+i) < BOARD_HEIGHT && (x+ii) < BOARD_WIDTH) ) {
                continue;
            }

            Cell whatIsThis = board[y+i][x+ii];

            if (board[y + i][x + ii] == oppositeOf(token)) {

                pos.x = x;
                pos.y = y;

                dir.x = ii;
                dir.y = i;

                if(isLegalMove(pos, dir, token, board)) {
                    legalMove = TRUE;

                    board[pos.y][pos.x] = token;
                    flipPieces( pos, dir, token, board );
                }
            }
        }
    }


    return legalMove;
}

Boolean isLegalMove(Position pos, Direction dir, Cell token, Cell board[8][8]) {
    Position newPos;

    if (board[pos.y + dir.y][pos.x + dir.x] == token) {
        return TRUE;
    }

    if (board[pos.y + dir.y][pos.x + dir.x] == oppositeOf(token)) {
        newPos.x = pos.x + dir.x;
        newPos.y = pos.y + dir.y;

        return isLegalMove(newPos, dir, token, board);
    }

    return FALSE;

}

void flipPieces(Position pos, Direction dir, Cell token, Cell board[8][8]) {
    Position newPos;

    if ( !((pos.y+dir.y) < BOARD_HEIGHT && (pos.x+dir.x) < BOARD_WIDTH) ) {
        return;
    }

    if (board[pos.y + dir.y][pos.x + dir.x] == token) {
        return;
    }

    if (board[ pos.y + dir.y ][ pos.x + dir.x ] == oppositeOf(token)) {
        board[ pos.y + dir.y ][ pos.x + dir.x ] = token;

        newPos.x = pos.x + dir.x;
        newPos.y = pos.y + dir.y;

        flipPieces(newPos, dir, token, board);
    }
}

/* Return the opposite token of the one passed in */
Cell oppositeOf(Cell tokenToFlip) {
    return (tokenToFlip == CYAN) ? RED : CYAN;
}

/**
 * Simply counts how many locations contain the token specified on board.
 **/
unsigned gameScore(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Cell token)
{
    unsigned int sum = 0;

    int i, ii;
    for ( i = 0; i < BOARD_WIDTH; i++ ) {
        for( ii = 0; ii < BOARD_HEIGHT; ii++ ) {
            /* Add 1 if the token matches, otherwise don't add anything */
            sum += (board[i][ii] == token) ? 1 : 0;
        }
    }

    return sum;
}

/**
 * Swaps the two player pointers so that first points to second and vice versa.
 **/
void swapPlayers(Player ** first, Player ** second)
{
    Player *temp = *first;
    *first = *second;
    *second = temp;
}
