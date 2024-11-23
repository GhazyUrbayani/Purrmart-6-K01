#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include "./boolean.h"

/**
 * @brief Menyalin memori dari sumber ke tujuan.
 */
void* mem_salin(void *dest, const void *src, size_t n);

/**
 * @brief Menghitung panjang string.
 */
size_t str_len(const char *str);

/**
 * @brief Mengalokasikan dan menyalin elemen.
 */
void* alokasi_salin(const void *item, size_t itemSize);

/// @brief Comparing dua string. Apakah sama atau beda.
/// @param s1 string pertama
/// @param s2 string kedua
/// @return returns true jika kedua string sama.
boolean str_compare(char s1[],char s2[]);
/* 
    Kasuses:
    1. s1 ATAU s2 kosong
    2. s1 DAN s2 kosong
    3. s1 beda ukuran dengan s2
    4. s1 atau s2 ada yang memiliki karakter berbeda dengan the other.
 */

#endif

/// @brief Menggabungkan 2 string
/// @param s1 awal
/// @param s2 akhir
/// @return pointer ke string
char *str_concat(char *s1, char *s2);