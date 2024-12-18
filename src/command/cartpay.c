#include "cart.h"
#include "utils.h"
#include "mesinkata.h"
#include <stdio.h>

void CartPay(Cart *C, Stack *history, int *userMoney) {
    if (C->count == 0) {
        printf("Keranjang kamu kosong!\n");
        return; // Tidak ada yang bisa dibeli
    }

    int totalCost = 0;
    char itemWithMaxTotal[MAX_NAME_LEN];
    int maxTotal = 0;

    // Menampilkan rincian keranjang
    printf("Kamu akan membeli barang-barang berikut.\n");
    printf("Kuantitas  Nama    Total\n");
    for (int i = 0; i < C->count; i++) {
        int itemTotal = C->quantities[i] * GetItemPrice(C->names[i]); // Menghitung total harga item
        totalCost += itemTotal; // Menambahkan ke total biaya
        printf("%d          %s    %d\n", C->quantities[i], C->names[i], itemTotal);

        // Menentukan item dengan total harga terbesar
        if (itemTotal > maxTotal || (itemTotal == maxTotal && str_compare(C->names[i], itemWithMaxTotal) > 0)) {
            maxTotal = itemTotal;
            mem_salin(itemWithMaxTotal, C->names[i], str_len(C->names[i]) + 1); // Menyalin nama item
        }
    }

    printf("Total biaya yang harus dikeluarkan adalah %d, apakah jadi dibeli? (Ya/Tidak): ", totalCost);
    
    WordList wl;
    ReadWords(&wl); // Membaca input pengguna

    // Validasi input
    if (wl.count > 0 && str_compare(GetWord(wl, 0), "Ya")) {
        if (*userMoney >= totalCost) {
            *userMoney -= totalCost; // Mengurangi uang pengguna
            Push(history, itemWithMaxTotal); // Menyimpan riwayat pembelian
            printf("Selamat kamu telah membeli barang-barang tersebut!\n");
        } else {
            printf("Uang kamu hanya %d, tidak cukup untuk membeli keranjang!\n", *userMoney);
        }
    } else if (wl.count > 0 && str_compare(GetWord(wl, 0), "Tidak")) {
        printf("Pembelian dibatalkan.\n");
    } else {
        printf("Input tidak valid. Pembelian dibatalkan.\n");
    }
}