#include "cart.h"

void CartRemove(Set *S, Cart *C, char *item, int qty) {
    for (int i = 0; i < S->Count; i++) {
        if (str_compare(C->names[i], item)) {
            if (C->quantities[i] < qty) {
                printf("Tidak berhasil mengurangi, hanya terdapat %d %s pada keranjang!\n", C->quantities[i], item);
                return;
            }
            C->quantities[i] -= qty;
            if (C->quantities[i] == 0) {
                Delete(S, i);
                for (int j = i; j < S->Count; j++) {
                    str_copy(C->names[j], C->names[j + 1]);
                    C->quantities[j] = C->quantities[j + 1];
                }
                printf("Berhasil menghapus %s dari keranjang belanja!\n", item);
            } else {
                printf("Berhasil mengurangi %d %s dari keranjang belanja!\n", qty, item);
            }
            return;
        }
    }
    printf("Barang %s tidak ada di keranjang belanja!\n", item);
}