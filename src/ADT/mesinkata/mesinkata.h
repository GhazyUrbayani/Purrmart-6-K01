#ifndef MESIN_KATA_H
#define MESIN_KATA_H

#include "./../mesinkarakter/mesinkarakter.h"

/* Definisi Word */
#define MESINKATA_NMax 100  // Panjang maksimal kata yang dapat diproses

typedef struct {
    char TabWord[MESINKATA_NMax]; // Array untuk menyimpan karakter kata
    int Length;                  // Panjang kata
} Word;

/* State Mesin Kata */
extern Word currentWord;  // Kata yang sedang diproses
extern boolean EndWord;   // Menandakan apakah sudah mencapai akhir kata

/* *** Konstruktor Mesin Kata *** */
/**
 * @brief Memulai mesin kata dari file.
 * @param filename Lokasi file yang akan dibaca.
 */
void STARTWORD(const char *filename);

/**
 * @brief Memulai mesin kata dari input standar (stdin).
 */
void STARTWORDINPUT(void);

/**
 * @brief Menggerakkan mesin kata ke kata berikutnya.
 */
void ADVWORD(void);

/**
 * @brief Membaca kalimat hingga menemukan karakter newline.
 */
void ADVSENTENCENL(void);

/**
 * @brief Melewati karakter kosong (spasi atau newline).
 */
void IgnoreBlank(void);

/* *** Fungsi Utilitas *** */
/**
 * @brief Mengecek apakah dua kata sama.
 * @param w Kata yang akan dibandingkan dengan currentWord.
 * @return True jika kata sama, false jika tidak.
 */
boolean WordEqual(Word w);

/**
 * @brief Mengonversi kata menjadi bilangan integer.
 * @param w Kata yang akan dikonversi.
 * @return Bilangan integer yang sesuai, atau -1 jika bukan angka.
 */
int WordToInt(Word w);

/**
 * @brief Menampilkan kata ke output.
 * @param w Kata yang akan ditampilkan.
 */
void printWord(Word w);

/**
 * @brief Mengubah string menjadi tipe Word.
 * @param str String yang akan diubah.
 * @return Tipe Word hasil konversi.
 */
Word stringToWord(const char *str);

/**
 * @brief Menyalin isi string ke buffer baru.
 * @param new Buffer tujuan salinan string.
 * @param str String sumber.
 */
void CopyString(char *new, const char *str);

#endif // MESIN_KATA_H
