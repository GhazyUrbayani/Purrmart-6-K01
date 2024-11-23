# include <stdio.h>
# include "./../structs/user.h"

void tebakangka(User *users) {
    (*users).money -= 200; // Biaya main tebak angka
    int angka = rand() % 100 + 1;
    int tebakan;
    int nyawa = 10;
    printf("Halo, selamat datang di permainan tebak angka!\n");
    printf("Silakan tebak angka dari 1-100\n");
    while (nyawa > 0) {
        int hadiah = 400 - (400-220)/(10-nyawa);
        printf("Masukkan tebakan: ");
        scanf("%d", &tebakan);
        if (tebakan == angka) {
            (*users).money += hadiah;
            printf("YEYYY!!! KAMU BERHASIL MENEBAK ANGKA YANG BENAR\n");
            printf("KAMU MENDAPATKAN %d KOIN.\n", hadiah);
            return;
        } else if (tebakan < angka) {
            printf("Coba naikin angka tebakannya.\n");
        } else {
            printf("Kamu nebak angkanya terlalu besar.\n");
        }
        nyawa--;
    }
    printf("YAHHH KAMU KALAH\n Angka yang benar adalah %d.\n", angka);
}