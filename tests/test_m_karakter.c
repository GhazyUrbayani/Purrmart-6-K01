#include <stdio.h>
#include <stdlib.h>
#include "./../src/ADT/mesinkarakter/mesinkarakter.h"

void ujiBacaDariFile(const char *filename) {
    printf("\n[Uji START dari File: %s]\n", filename);
    START(filename);
    if (EOP) {
        printf("File kosong atau tidak dapat dibaca.\n");
    } else {
        printf("Isi file '%s':\n", filename);
        while (!EOP) {
            printf("%c", currentChar);
            ADV();
        }
    }
    END();
    printf("\nSelesai membaca file.\n");
}

void ujiBacaDariStdin() {
    printf("\n[Uji STARTINPUT dari stdin]\n");
    printf("Masukkan teks (akhiri input dengan EOF - Ctrl+D di Linux/Mac, Ctrl+Z di Windows):\n");
    STARTINPUT();
    printf("\nAnda memasukkan:\n");
    while (!EOP) {
        printf("%c", currentChar);
        ADV();
    }
    printf("\nSelesai membaca dari stdin.\n");
}

void ujiDeteksiBlank() {
    printf("\n[Uji IsBlank]\n");
    char karakterUji[] = {' ', '\n', 'a', '1', '\t'};
    for (int i = 0; i < 5; i++) {
        currentChar = karakterUji[i];
        printf("Karakter: '%c' => IsBlank: %s\n", currentChar, IsBlank() ? "Benar" : "Salah");
    }
}

void ujiContainsSpace() {
    printf("\n[Uji containsSpace]\n");
    const char *stringUji[] = {
        "Halo Dunia",
        "TidakAdaSpasi",
        " ",
        "",
        "    ", // Spasi banyak
        "Baris\nBaru"
    };

    for (int i = 0; i < 6; i++) {
        printf("String: '%s' => containsSpace: %s\n",
               stringUji[i],
               containsSpace(stringUji[i]) ? "Benar" : "Salah");
    }
}

int main() {
    printf("=== SUITE UJI MESIN KARAKTER ===\n");

    // Uji membaca dari berbagai file
    ujiBacaDariFile("./tests/oneline.txt");     // File dengan satu baris teks
    ujiBacaDariFile("./tests/empty.txt");       // File kosong
    ujiBacaDariFile("./tests/specialchars.txt");// File dengan karakter spesial
    ujiBacaDariFile("./tests/whitespace.txt"); // File hanya berisi spasi

    // Uji membaca dari stdin
    ujiBacaDariStdin();

    // Uji fungsi utilitas
    ujiDeteksiBlank();
    ujiContainsSpace();

    printf("\n=== PENGUJIAN SELESAI ===\n");
    return 0;
}
