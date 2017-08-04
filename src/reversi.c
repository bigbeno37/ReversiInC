#include "reversi.h"

long getUserInput(char *input) {
    long choice = 0;
    printf("Please enter your choice: ");

    if ( fgets(input, sizeof(input), stdin) != NULL ) {
        choice = strtol(input, NULL, 10);
    }
    return choice;
}

void displayWelcome() {
    puts("Welcome to Reversi!");
    puts("===================");
    puts("Select an option:");
    puts("1. Play a game");
    puts("2. Quit the program");
}

int main()
{
    char input[2];
    char playerOneName[NAMELEN];
    char playerTwoName[NAMELEN];

    Player player1;

    displayWelcome();
//    long int choice = getUserInput(input);

    Boolean userHasEnteredValidOption = FALSE;

    Cell board[BOARD_HEIGHT][BOARD_WIDTH];

//    initBoard(board);
//    displayBoard(board, NULL, NULL);

    initFirstPlayer(&player1);

//    while (!userHasEnteredValidOption) {
//        switch (choice) {
//            case 2:
//                puts("Goodbye!");
//                userHasEnteredValidOption = TRUE;
//
//                break;
//            case 1:
//                userHasEnteredValidOption = TRUE;
//
//                printf("Player 1, enter your name: ");
//                fgets(playerOneName, sizeof(playerOneName), stdin);
//                strtok(playerOneName, "\n");
//
//                printf("Player 2, enter your name: ");
//                fgets(playerTwoName, sizeof(playerTwoName), stdin);
//                strtok(playerTwoName, "\n");
//
//                printf("Player 1 is %s, Player 2 is %s", playerOneName, playerTwoName);
//
//                break;
//            default:
//                printf("Invalid selection! ");
//                choice = getUserInput(input);
//
//                break;
//        }
//    }


    return EXIT_SUCCESS;
}
