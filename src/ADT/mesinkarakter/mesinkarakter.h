#ifndef MESIN_KARAKTER_H
#define MESIN_KARAKTER_H

#include "../boolean.h"
#include <stdio.h>

/* Definisi Karakter */
#define BLANK ' '
#define NEWLINE '\n'

/* State Mesin Karakter */
extern char currentChar;  // Karakter saat ini yang sedang dibaca
extern boolean EOP;       // Menandakan apakah sudah mencapai akhir file

/* *** Konstruktor Mesin Karakter *** */
// Memulai membaca karakter dari sebuah file
void START(const char *filename);

// Memulai membaca karakter dari input standar
void STARTINPUT(void);

// Menggerakkan mesin karakter ke karakter berikutnya
void ADV(void);

// Menutup pita input secara eksplisit (baik file atau stdin)
void END(void);

/* *** Fungsi Utilitas *** */
// Mengecek apakah karakter saat ini adalah karakter kosong (spasi atau newline)
boolean IsBlank(void);

// Mengecek apakah sebuah string mengandung karakter spasi
boolean containsSpace(const char *str);

#endif // MESIN_KARAKTER_H
