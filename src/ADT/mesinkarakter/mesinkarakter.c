#include "mesinkarakter.h"
#include <stdio.h>
#include <stdlib.h>

/* State Mesin Karakter */
char currentChar;      // Karakter yang sedang diproses
boolean EOP = false;   // Status apakah sudah mencapai akhir file
static FILE *pita = NULL;  // Pointer ke file yang sedang dibaca
static int retval = 0;     // Status hasil pembacaan karakter

// Memulai mesin karakter dari file
void START(const char *filename) {
    pita = fopen(filename, "r");
    if (pita == NULL) {
        EOP = true;
        fprintf(stderr, "Error: File '%s' tidak ditemukan atau tidak dapat dibuka.\n", filename);
        return;
    }
    ADV();  // Memulai pembacaan karakter pertama
}

/// @brief Memulai mesin karakter dari input standar (stdin)
/// @param  void
void STARTINPUT(void) {
    pita = stdin;
    EOP = false;
    ADV();  // Memulai pembacaan karakter pertama
}

/// @brief Menggerakkan mesin karakter ke karakter berikutnya secara otomatis akan mengatur EOP jika mencapai akhir file.
/// @param  void
void ADV(void) {
    if (pita == NULL) {
        fprintf(stderr, "Error: Input stream belum diinisialisasi.\n");
        EOP = true;
        return;
    }

    retval = fscanf(pita, "%c", &currentChar);
    EOP = (retval == EOF);  // Mengecek apakah sudah mencapai akhir file

    if (EOP && pita != stdin) {
        fclose(pita);
        pita = NULL;
    }
}

// Menutup pita input dan mengatur ulang state mesin karakter
void END(void) {
    if (pita != NULL && pita != stdin) {
        fclose(pita);
    }
    pita = NULL;
    EOP = true;
}

// Mengecek apakah karakter saat ini adalah karakter kosong (spasi atau newline)
boolean IsBlank(void) {
    return currentChar == BLANK || currentChar == NEWLINE;
}

// Mengecek apakah sebuah string mengandung karakter spasi
boolean containsSpace(const char *str) {
    if (str == NULL) {
        fprintf(stderr, "Error: String NULL diberikan ke containsSpace.\n");
        return false;
    }

    while (*str) {
        if (*str == BLANK) {
            return true;
        }
        str++;
    }
    return false;
}
