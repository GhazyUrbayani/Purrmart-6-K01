#include "../command/start.h"
#include <stdio.h>

int main() {
    ListUser users;
    ListBarang items;

    // Path file konfigurasi
    STARTWORDINPUT();
    char *filename = currentWord.TabWord;

    // Panggil fungsi START
    printf("Membaca file konfigurasi...\n");
    STARTPROGRAM(&users, &items, filename);

    // Cetak hasil barang
    printf("\nDaftar Barang:\n");
    for (int i = 0; i < items.neff; i++) {
        printf("  - Nama: %s, Harga: %d\n", items.barang[i].name, items.barang[i].price);
    }

    // Cetak hasil pengguna
    printf("\nDaftar Pengguna:\n");
    for (int i = 0; i < users.neff; i++) {
        printf("  - Nama: %s, Uang: %d, Password: %s\n",
               users.users[i].name, users.users[i].money, users.users[i].password);
    }

    // Bebaskan memori barang
    free(items.barang);

    return 0;
}
