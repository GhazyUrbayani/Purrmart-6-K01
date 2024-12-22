#include "cart.h"
#include "store.h"

void CartAdd(Set *S, Cart *C, DList *item_list, char *item, int qty) {
    boolean found = false;
    for (int i = 0; i < item_list->size; i++) {
        if (str_compare(id_getItem(item_list, i)->name, item)) {
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
