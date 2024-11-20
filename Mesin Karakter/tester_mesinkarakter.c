#include <stdio.h>
#include <stdlib.h>
#include "mesinkarakter.h"

int main() {
    printf("=== TESTER MESIN KARAKTER ===\n");

    // Test START dari file
    printf("\n1. Test START (membaca dari file)...\n");
    START("testfile.txt"); // Ubah "testfile.txt" ke nama file yang tersedia
    while (!EOP) {
        printf("%c", currentChar);
        ADV();
    }
    END();
    printf("\nSelesai membaca dari file.\n");

    // Test STARTINPUT dari stdin
    printf("\n2. Test STARTINPUT (membaca dari stdin)...\n");
    printf("Masukkan teks diakhiri dengan tanda EOF (Ctrl+D di Linux/Mac, Ctrl+Z di Windows):\n");
    STARTINPUT();
    while (!EOP) {
        printf("%c", currentChar);
        ADV();
    }
    printf("\nSelesai membaca dari stdin.\n");

    return 0;
}
