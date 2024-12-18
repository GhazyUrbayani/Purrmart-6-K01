#include "history.h"
#include <stdio.h>

void ShowHistory(Stack *history, int n) {
    if (history->top == -1) {
        printf("Kamu belum membeli barang apapun!\n");
        return; // Tidak ada riwayat pembelian
    }

    printf("Riwayat pembelian barang:\n");
    int count = 0;
    for (int i = history->top; i >= 0 && count < n; i--, count++) {
        char transaction[MAX_NAME_LEN];
        Pop(history, transaction); // Mengambil transaksi dari stack
        printf("%d. %s\n", count + 1, transaction);
    }
}