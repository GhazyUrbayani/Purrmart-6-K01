#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>

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

#endif
