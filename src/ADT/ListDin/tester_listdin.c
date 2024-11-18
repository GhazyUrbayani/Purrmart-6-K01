#include "listdin.h"
#include <stdlib.h>
#include <stdio.h>
// ListDin: Memastikan list dinamis dapat ditambahkan, dihapus, dan dicari elemen dengan benar

int main() {
    ListDin l;
    int val;

    // Buat list dinamis dengan kapasitas 5
    printf("Membuat ListDin dengan kapasitas 5...\n");
    CreateListDin(&l, 5);

    // Tambahkan elemen ke list
    printf("Menambahkan elemen: 10, 20, 30...\n");
    InsertLast(&l, 10);
    InsertLast(&l, 20);
    InsertLast(&l, 30);

    // Tampilkan isi list
    printf("Isi ListDin: ");
    for (int i = 0; i < l.neff; i++) {
        printf("%d ", l.buffer[i]);
    }
    printf("\n");

    // Cari elemen
    printf("Mencari elemen 20...\n");
    int idx = Find(l, 20);
    if (idx != IDX_UNDEF) {
        printf("Elemen 20 ditemukan di indeks %d\n", idx);
    } else {
        printf("Elemen 20 tidak ditemukan.\n");
    }

    // Hapus elemen terakhir
    printf("Menghapus elemen terakhir...\n");
    DeleteLast(&l, &val);
    printf("Elemen yang dihapus: %d\n", val);

    // Tampilkan isi list setelah penghapusan
    printf("Isi ListDin setelah penghapusan: ");
    for (int i = 0; i < l.neff; i++) {
        printf("%d ", l.buffer[i]);
    }
    printf("\n");

    // Deallocate list
    printf("Menghapus ListDin dari memori...\n");
    DeallocateListDin(&l);

    return 0;
}
