#ifndef UTILITY_H
#define UTILITY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <assert.h>

typedef enum boolean {
    FALSE = 0,
    TRUE
} Boolean;

typedef struct position {
    int x;
    int y;
} Position;

typedef struct direction {
    int x;
    int y;
} Direction;

#define NEW_LINE_SPACE 1
#define NULL_SPACE 1

/**
 * This is used to compensate for the extra character spaces taken up by
 * the '\n' and '\0' when input is read through fgets().
 **/
#define EXTRA_SPACES (NEW_LINE_SPACE + NULL_SPACE)
#define CHOICE_SIZE (1 + EXTRA_SPACES)

#define EMPTY_STRING ""

/**
 * Call this function whenever you detect buffer overflow.
 **/
void readRestOfLine();

void displayWelcome();

void getUserInput( char *buffer, int charsToRead );

long getUserChoice();

#endif
