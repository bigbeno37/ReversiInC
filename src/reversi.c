#include "reversi.h"

long getUserInput(char *input) {
    long choice = 0;
    printf("Please enter your choice: ");

    if ( fgets(input, sizeof(input), stdin) != NULL ) {
        choice = strtol(input, NULL, 10);
        strcpy(input, "");
    }
    return choice;
}

int main()
{
    char input[2];

    puts("Welcome to Reversi!");
    puts("===================");
    puts("Select an option:");
    puts("1. Play a game");
    puts("2. Quit the program");
    long int choice = getUserInput(input);

    Boolean userHasEnteredValidOption = FALSE;

    while (!userHasEnteredValidOption) {
        switch (choice) {
            case 2:
                puts("Goodbye!");
                userHasEnteredValidOption = TRUE;

                break;
            case 1:
                puts("Welcome to the matrix!");
                userHasEnteredValidOption = TRUE;

                break;
            default:
                printf("Invalid selection! ");
                choice = getUserInput(input);

                break;
        }
    }


    return EXIT_SUCCESS;
}
