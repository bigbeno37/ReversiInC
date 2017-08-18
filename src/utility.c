#include "utility.h"

/**
 * Function required to be used when clearing the buffer. It simply reads
 * each char from the buffer until the buffer is empty again. Please refer
 * to the materials on string and buffer handling in the course for more
 * information.
 **/
void readRestOfLine() {
    int ch;
    while ( ch = getc( stdin ), ch != EOF && ch != '\n' ) {} /* Gobble each character. */

    /* Reset the error status of the stream. */
    clearerr( stdin );
}

void displayWelcome() {
    puts( "Welcome to Reversi!" );
    puts( "===================" );
    puts( "Select an option:" );
    puts( "1. Play a game" );
    puts( "2. Quit the program" );
    printf( "Please enter your choice: " );
}

long getUserChoice() {
    Boolean correctInput = FALSE;
    char buffer[CHOICE_SIZE];
    strcpy( buffer, EMPTY_STRING );

    while ( !correctInput ) {
        correctInput = TRUE;

        /* Get the input and store it in name */
        fgets( buffer, CHOICE_SIZE, stdin );

        /* If name doesn't have a newline character (and thus the input was bigger than 20) */
        /* remove overflowed characters and ask for new input */
        if ( !strchr( buffer, '\n' )) {
            printf( "\nBuffer overflow! Please enter a valid choice: " );
            readRestOfLine();

            correctInput = FALSE;
        }
    }

    return strtol( buffer, NULL, 10 );

}

void getUserInput( char *buffer, int charsToRead ) {
    Boolean correctInput = FALSE;

    strcpy( buffer, EMPTY_STRING );

    while ( !correctInput ) {
        correctInput = TRUE;

        /* Get the input and store it in name */
        fgets( buffer, charsToRead, stdin );

        /* If name doesn't have a newline character (and thus the input was bigger than 20) */
        /* remove overflowed characters and ask for new input */
        if ( !strchr( buffer, '\n' )) {
            printf( "Buffer overflow! Enter a smaller name: " );
            readRestOfLine();

            correctInput = FALSE;
        } else if ( buffer[ 0 ] == '\n' ) {
            printf( "Please enter a name: " );
            correctInput = FALSE;
        }
    }

    buffer[ strlen( buffer ) - 1 ] = '\0';
}
