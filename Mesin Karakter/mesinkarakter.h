#ifndef MESIN_KARAKTER_H
#define MESIN_KARAKTER_H

#include "../boolean.h"

/* Definisi karakter */
#define MARK '.'
#define BLANK ' '
#define NEWLINE '\n'

/* State Mesin Karakter */
extern char currentChar;
extern boolean EOP;

/* *** Konstruktor Mesin Karakter *** */
void START(const char *filename);  // Memulai mesin karakter dari file
void STARTINPUT();                 // Memulai mesin karakter dari stdin
void ADV();                        // Menggerakkan mesin karakter ke karakter berikutnya
void END();                        // Menutup pita atau stdin secara eksplisit

/* *** Fungsi dan Validasi *** */
boolean IsBlank();                 // Mengecek apakah karakter adalah blank
boolean containsSpace(const char *str); // Mengecek apakah string mengandung spasi

#endif
