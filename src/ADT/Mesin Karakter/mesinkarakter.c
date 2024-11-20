#include "mesinkarakter.h"
#include <stdio.h>
#include <stdlib.h>

/* State Mesin Karakter */
char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

/* Memulai mesin karakter */
void START(const char *filename) {
    pita = fopen(filename, "r");
    if (pita == NULL) {
        EOP = true;
        return;
    }
    ADV();
}

/* Memulai mesin karakter dari input stdin */
void STARTINPUT() {
    pita = stdin;
    ADV();
}

/* Menggerakkan mesin karakter */
void ADV() {
    retval = fscanf(pita, "%c", &currentChar);
    EOP = (retval == EOF);
    if (EOP && pita != stdin) {
        fclose(pita);
    }
}

/* Menutup pita atau stdin */
void END() {
    if (pita != NULL && pita != stdin) {
        fclose(pita);
    }
    EOP = true;
}

/* Mengecek apakah karakter adalah blank */
boolean IsBlank() {
    return currentChar == BLANK || currentChar == NEWLINE;
}

/* Mengecek apakah string mengandung spasi */
boolean containsSpace(const char *str) {
    while (*str) {
        if (*str == BLANK) return true;
        str++;
    }
    return false;
}
