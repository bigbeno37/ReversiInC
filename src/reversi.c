#include "reversi.h"

//long getUserInput(char *input) {
//    long choice = 0;
//    printf("Please enter your choice: ");
//
//    if ( fgets(input, sizeof(input), stdin) != NULL ) {
//        choice = strtol(input, NULL, 10);
//    }
//    return choice;
//}

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
    Cell board[BOARD_HEIGHT][BOARD_WIDTH];

    Player player1;
    Player player2;

    displayWelcome();
    playGame(&player1, &player2);

    return EXIT_SUCCESS;
}
