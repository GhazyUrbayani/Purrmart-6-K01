#ifndef MESIN_KATA_H
#define MESIN_KATA_H

#include "./../mesinkarakter/mesinkarakter.h"

/* Definisi Word */
#define MESINKATA_NMax 100  // Panjang maksimal kata yang dapat diproses

typedef struct {
    char TabWord[MESINKATA_NMax]; // Array untuk menyimpan karakter kata
    int Length;                  // Panjang kata
} Word;

#define STRING(w) w.TabWord  // Shortcut untuk mengakses array karakter dari Word

/* State Mesin Kata */
extern Word currentWord;  // Kata yang sedang diproses
extern boolean EndWord;   // Menandakan apakah sudah mencapai akhir kata

/* *** Konstruktor Mesin Kata *** */
// Memulai mesin kata dari file.
int STARTWORD(const char *filename);

// Memulai mesin kata dari input standar (stdin).
void STARTWORDINPUT(void);

// Menggerakkan mesin kata ke kata berikutnya.
void ADVWORD(void);

// Membaca kalimat hingga menemukan karakter newline.
void ADVSENTENCENL(void);

void STARTSENTENCEINPUT(void);

// Melewati karakter kosong (spasi atau newline)
void IgnoreBlank(void);

/* *** Fungsi Utilitas *** */
// Mengecek apakah dua kata sama
boolean WordEqual(Word w);

// Mengonversi kata menjadi bilangan integer
int WordToInt(Word w);

// Menampilkan kata ke output
void printWord(Word w);

// Mengubah string menjadi tipe Word
Word stringToWord(const char *str);

// Menyalin isi string ke buffer baru
void CopyString(char *new, const char *str);

#endif // MESIN_KATA_H
