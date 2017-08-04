#include "utility.h"
#include "player.h"

/**
 * Function required to be used when clearing the buffer. It simply reads
 * each char from the buffer until the buffer is empty again. Please refer
 * to the materials on string and buffer handling in the course for more
 * information.
 **/
void readRestOfLine()
{
    int ch;
    while(ch = getc(stdin), ch != EOF && ch != '\n')
    { } /* Gobble each character. */

    /* Reset the error status of the stream. */
    clearerr(stdin);
}

void getUserInput(char *buffer) {
    strcpy(buffer, "");

    Boolean correctInput = FALSE;

    while (!correctInput) {
        correctInput = TRUE;

        // Get the input and store it in name
        fgets(buffer, NAMELEN, stdin);

        // If name doesn't have a newline character (and thus the input was bigger than 20)
        // remove overflowed characters and ask for new input
        if (!strchr(buffer, '\n')) {
            printf("The name entered was too long! Enter a smaller name: ");
            readRestOfLine();

            correctInput = FALSE;
        }
    }
}
