#include "cart.h"

void CartAdd(Set *S, Cart *C, Store *store, char *item, int qty) {
    boolean found = false;
    for (int i = 0; i < store->count; i++) {
        if (str_compare(store->items[i], item)) {
            found = true;
            break;
        }
    }
    if (!found) {
        printf("Barang %s tidak ada di toko!\n", item);
        return;
    }

    for (int i = 0; i < S->Count; i++) {
        if (str_compare(C->names[i], item)) {
            C->quantities[i] += qty;
            printf("Berhasil menambahkan %d %s ke keranjang belanja!\n", qty, item);
            return;
        }
    }

    if (!IsFull(*S)) {
        Insert(S, S->Count);
        str_copy(C->names[S->Count - 1], item);
        C->quantities[S->Count - 1] = qty;
        printf("Berhasil menambahkan %d %s ke keranjang belanja!\n", qty, item);
    } else {
        printf("Keranjang belanja penuh!\n");
    }
}