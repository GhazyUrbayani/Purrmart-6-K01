#ifndef MESIN_KATA_H
#define MESIN_KATA_H

#include "../mesinkarakter.h"

/* Definisi word */
#define NMax 100

typedef struct {
    char TabWord[NMax];
    int Length;
} Word;

/* State Mesin Kata */
extern Word currentWord;
extern boolean EndWord;

/* *** Konstruktor Mesin Kata *** */
void STARTWORD(const char *filename);  // Memulai mesin kata dari file
void STARTWORDINPUT();                 // Memulai mesin kata dari stdin
void ADVWORD();                        // Menggerakkan mesin kata ke kata berikutnya
void ADVSENTENCENL();                  // Membaca kalimat hingga newline

/* *** Utility Functions *** */
boolean WordEqual(Word w);             // Mengecek kesamaan kata
int WordToInt(Word w);                 // Mengonversi kata menjadi integer
void printWord(Word w);                // Menampilkan kata ke output
Word stringToWord(const char *str);    // Mengubah string menjadi Word

#endif
