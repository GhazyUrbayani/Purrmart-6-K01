#include "mesinkata.h"
#include <stdio.h>

/* State Mesin Kata */
Word currentWord;
boolean EndWord;

/* Memulai mesin kata */
void STARTWORD(const char *filename) {
    START(filename);
    ADVWORD();
}

/* Memulai mesin kata dari input stdin */
void STARTWORDINPUT() {
    STARTINPUT();
    ADVWORD();
}

/* Menggerakkan mesin kata */
void ADVWORD() {
    int i = 0;
    while (IsBlank() && !EOP) {
        ADV();
    }

    if (EOP) {
        EndWord = true;
    } else {
        EndWord = false;
        while (!IsBlank() && !EOP && i < NMax) {
            currentWord.TabWord[i] = currentChar;
            i++;
            ADV();
        }
        currentWord.Length = i;
        currentWord.TabWord[i] = '\0'; // Null-terminate string
    }
}

/* Membaca kalimat hingga newline */
void ADVSENTENCENL() {
    int i = 0;
    while (!EOP && currentChar != NEWLINE && i < NMax) {
        currentWord.TabWord[i] = currentChar;
        i++;
        ADV();
    }
    currentWord.Length = i;
    currentWord.TabWord[i] = '\0'; // Null-terminate string
}

/* Mengecek kesamaan kata */
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

/* Mengonversi kata menjadi integer */
int WordToInt(Word w) {
    int result = 0;
    for (int i = 0; i < w.Length; i++) {
        if (w.TabWord[i] >= '0' && w.TabWord[i] <= '9') {
            result = result * 10 + (w.TabWord[i] - '0');
        } else {
            return -1; // Return -1 jika bukan angka
        }
    }
    return result;
}

/* Menampilkan kata ke output */
void printWord(Word w) {
    for (int i = 0; i < w.Length; i++) {
        printf("%c", w.TabWord[i]);
    }
}

/* Mengubah string menjadi Word */
Word stringToWord(const char *str) {
    Word w;
    int i = 0;
    while (str[i] != '\0' && i < NMax) {
        w.TabWord[i] = str[i];
        i++;
    }
    w.Length = i;
    return w;
}
