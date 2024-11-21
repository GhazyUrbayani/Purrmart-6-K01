#include "mesinkata.h"
#include <stdio.h>

#define STRING(w) w.TabWord  // Shortcut untuk mengakses array karakter dari Word

/* State Mesin Kata */
Word currentWord;  // Kata yang sedang diproses
boolean EndWord;   // Menandakan apakah sudah mencapai akhir kata

/**
 * @brief Memulai mesin kata dari file.
 *        Jika file kosong atau tidak bisa dibaca, akan mencetak pesan error.
 * @param filename Lokasi file yang akan dibaca.
 */
void STARTWORD(const char *filename) {
    START(filename);
    if (!EOP) {
        ADVWORD();
    } else {
        fprintf(stderr, "Error: File kosong atau tidak bisa dibaca.\n");
    }
}

/**
 * @brief Memulai mesin kata dari input standar (stdin).
 */
void STARTWORDINPUT(void) {
    STARTINPUT();
    ADVWORD();
}

/**
 * @brief Melewati karakter kosong (spasi atau newline) hingga menemukan karakter pertama yang bukan kosong.
 */
void IgnoreBlank(void) {
    while (IsBlank() && !EOP) {
        ADV();
    }
}

/**
 * @brief Menggerakkan mesin kata ke kata berikutnya.
 *        Jika mencapai akhir file, EndWord akan diatur menjadi true.
 */
void ADVWORD(void) {
    int i = 0;
    IgnoreBlank();

    if (EOP) {
        EndWord = true;
    } else {
        EndWord = false;
        while (!IsBlank() && !EOP && i < MESINKATA_NMax) {
            currentWord.TabWord[i] = currentChar;
            i++;
            ADV();
        }
        currentWord.Length = i;
        currentWord.TabWord[i] = '\0'; // Menambahkan null-terminator
    }
}

/**
 * @brief Membaca kalimat hingga menemukan karakter newline.
 */
void ADVSENTENCENL(void) {
    int i = 0;
    while (!EOP && currentChar != NEWLINE && i < MESINKATA_NMax) {
        currentWord.TabWord[i] = currentChar;
        i++;
        ADV();
    }
    currentWord.Length = i;
    currentWord.TabWord[i] = '\0'; // Menambahkan null-terminator
}

/**
 * @brief Mengecek apakah kata saat ini sama dengan kata yang diberikan.
 * @param w Kata yang akan dibandingkan.
 * @return True jika sama, false jika tidak.
 */
boolean WordEqual(Word w) {
    if (currentWord.Length != w.Length) {
        return false;
    }
    for (int i = 0; i < currentWord.Length; i++) {
        if (currentWord.TabWord[i] != w.TabWord[i]) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Mengonversi kata menjadi bilangan integer.
 * @param w Kata yang akan dikonversi.
 * @return Bilangan integer, atau -1 jika kata tidak valid.
 */
int WordToInt(Word w) {
    int result = 0;
    for (int i = 0; i < w.Length; i++) {
        if (w.TabWord[i] >= '0' && w.TabWord[i] <= '9') {
            result = result * 10 + (w.TabWord[i] - '0');
        } else {
            return -1; // Mengembalikan -1 jika ada karakter bukan angka
        }
    }
    return result;
}

/**
 * @brief Menampilkan kata ke output.
 * @param w Kata yang akan ditampilkan.
 */
void printWord(Word w) {
    for (int i = 0; i < w.Length; i++) {
        printf("%c", w.TabWord[i]);
    }
}

/**
 * @brief Mengubah string menjadi tipe Word.
 * @param str String yang akan diubah.
 * @return Tipe Word hasil konversi.
 */
Word stringToWord(const char *str) {
    Word w;
    int i = 0;
    while (str[i] != '\0' && i < MESINKATA_NMax) {
        w.TabWord[i] = str[i];
        i++;
    }
    w.TabWord[i] = '\0';
    w.Length = i;
    return w;
}

/**
 * @brief Menyalin isi string ke buffer baru.
 * @param new Buffer tujuan salinan string.
 * @param str String sumber.
 */
void CopyString(char *new, const char *str) {
    int i = 0;
    while (str[i] != '\0') {
        new[i] = str[i];
        i++;
    }
    new[i] = '\0';
}
