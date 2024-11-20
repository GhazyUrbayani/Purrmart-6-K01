#include <stdio.h>
#include <stdlib.h>
#include "mesinkata.h"

int main() {
    printf("=== TESTER MESIN KATA ===\n");

    // Test STARTWORD dari file
    printf("\n1. Test STARTWORD (membaca kata dari file)...\n");
    STARTWORD("testfile.txt"); // Ubah "testfile.txt" ke nama file yang tersedia
    while (!EndWord) {
        printWord(currentWord);
        printf("\n");
        ADVWORD();
    }
    printf("Selesai membaca kata dari file.\n");

    // Test STARTWORDINPUT dari stdin
    printf("\n2. Test STARTWORDINPUT (membaca kata dari stdin)...\n");
    printf("Masukkan teks diakhiri dengan tanda EOF (Ctrl+D di Linux/Mac, Ctrl+Z di Windows):\n");
    STARTWORDINPUT();
    while (!EndWord) {
        printWord(currentWord);
        printf("\n");
        ADVWORD();
    }
    printf("Selesai membaca kata dari stdin.\n");

    // Test ADVSENTENCENL (membaca kalimat hingga newline)
    printf("\n3. Test ADVSENTENCENL (membaca kalimat hingga newline)...\n");
    printf("Masukkan kalimat diakhiri dengan newline:\n");
    STARTWORDINPUT();
    ADVSENTENCENL();
    printWord(currentWord);
    printf("\nSelesai membaca kalimat.\n");

    // Test WordToInt dan WordEqual
    printf("\n4. Test WordToInt dan WordEqual...\n");
    Word numWord = stringToWord("12345");
    Word textWord = stringToWord("hello");
    printf("Konversi kata '12345' menjadi integer: %d\n", WordToInt(numWord));
    printf("Konversi kata 'hello' menjadi integer: %d (seharusnya -1 karena bukan angka)\n", WordToInt(textWord));
    Word compareWord = stringToWord("hello");
    printf("Apakah kata 'hello' dan 'hello' sama? %s\n", WordEqual(textWord, compareWord) ? "Ya" : "Tidak");

    return 0;
}
