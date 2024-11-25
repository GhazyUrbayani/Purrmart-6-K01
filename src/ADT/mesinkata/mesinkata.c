#include "mesinkata.h"
#include <stdio.h>

/* State Mesin Kata */
Word currentWord;  // Kata yang sedang diproses
boolean EndWord;   // Menandakan apakah sudah mencapai akhir kata

// Memulai mesin kata dari file.
int STARTWORD(const char *filename) {
    START(filename);
    if (!EOP) {
        ADVWORD();
        return true;
    } else {
        fprintf(stderr, "Error: File kosong atau tidak bisa dibaca.\n");
        return 0;
    }
}

// Memulai mesin kata dari input standar (stdin).
void STARTWORDINPUT(void) {
    rewind(stdin);
    STARTINPUT();
    ADVWORD();
}

void STARTSENTENCEINPUT(void) {
    rewind(stdin);
    STARTINPUT();

    int i = 0;

    while (!EOP && currentChar != '\n' && i < MESINKATA_NMax) {
        currentWord.TabWord[i] = currentChar;
        i++;
        ADV();
    }

    currentWord.Length = i;
    currentWord.TabWord[i] = '\0';

    EndWord = (i == 0);
}

// Melewati karakter kosong (spasi atau newline) hingga menemukan karakter pertama yang bukan kosong.
void IgnoreBlank(void) {
    while (IsBlank() && !EOP) {
        ADV();
    }
}

// Menggerakkan mesin kata ke kata berikutnya.
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

// Membaca kalimat hingga menemukan karakter newline.
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

// Mengecek apakah kata saat ini sama dengan kata yang diberikan.
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

//Mengonversi kata menjadi bilangan integer.
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

// Menampilkan kata ke output.
void printWord(Word w) {
    for (int i = 0; i < w.Length; i++) {
        printf("%c", w.TabWord[i]);
    }
}

// Mengubah string menjadi tipe Word.
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

// Menyalin isi string ke buffer baru.
void CopyString(char *new, const char *str) {
    int i = 0;
    while (str[i] != '\0') {
        new[i] = str[i];
        i++;
    }
    new[i] = '\0';
}
