#include "listdin.h"
#include <stdlib.h>
#include <stdio.h>
// ListDin: Memastikan list dinamis dapat ditambahkan, dihapus, dan dicari elemen dengan benar

int main() {
    // Variabel untuk pengujian
    ListDin l;
    Word w1 = {"Apple", 5};
    Word w2 = {"Banana", 6};
    Word w3 = {"Cherry", 6};
    Word w4 = {"Date", 4};
    ElType deletedElement;

    // 1. Buat ListDin dengan kapasitas awal
    printf("1. Membuat ListDin dengan kapasitas awal 2.\n");
    CreateListDin(&l, 2);
    printf("ListDin berhasil dibuat. Kapasitas: %d, Neff: %d\n", l.capacity, l.neff);

    // 2. Tambahkan elemen ke list
    printf("\n2. Menambahkan elemen ke ListDin.\n");
    InsertLast(&l, w1);
    InsertLast(&l, w2);
    printf("Elemen berhasil ditambahkan. Neff: %d\n", l.neff);
    printf("Isi List: [%s, %s]\n", l.buffer[0], l.buffer[1]);

    // 3. Memicu kapasitas otomatis (expand)
    printf("\n3. Memicu kapasitas otomatis (expand).\n");
    InsertLast(&l, w3);
    printf("Elemen berhasil ditambahkan. Kapasitas: %d, Neff: %d\n", l.capacity, l.neff);
    printf("Isi List: [%s, %s, %s]\n", l.buffer[0], l.buffer[1], l.buffer[2]);

    // 4. Menambahkan elemen lagi
    printf("\n4. Menambahkan elemen lagi untuk pengujian lainnya.\n");
    InsertLast(&l, w4);
    printf("Isi List: [%s, %s, %s, %s]\n", l.buffer[0], l.buffer[1], l.buffer[2], l.buffer[3]);

    // 5. Menghapus elemen pada indeks tertentu
    printf("\n5. Menghapus elemen pada indeks tertentu (idx = 1).\n");
    DeleteAt(&l, 1, &deletedElement);
    printf("Elemen di indeks 1 ('%s') berhasil dihapus.\n", deletedElement);
    printf("Isi List: [%s, %s, %s]\n", l.buffer[0], l.buffer[1], l.buffer[2]);

    // 6. Cari elemen
    printf("\n6. Mencari elemen 'Cherry' di ListDin.\n");
    int idx = indexOfDin(l, w3);
    if (idx != IDX_UNDEF) {
        printf("Elemen ditemukan di indeks: %d\n", idx);
    } else {
        printf("Elemen tidak ditemukan.\n");
    }

    // 7. Mengurutkan elemen secara ascending
    printf("\n7. Mengurutkan elemen secara ascending.\n");
    sortDin(&l, true);
    printf("Isi List setelah sorting ascending: [%s, %s, %s]\n", l.buffer[0], l.buffer[1], l.buffer[2]);

    // 8. Kompresi kapasitas
    printf("\n8. Mengompresi kapasitas ListDin.\n");
    compressListDin(&l);
    printf("ListDin berhasil dikompresi. Kapasitas: %d, Neff: %d\n", l.capacity, l.neff);

    // 9. Hapus elemen terakhir
    printf("\n9. Menghapus elemen terakhir dari ListDin.\n");
    DeleteLast(&l, &deletedElement);
    printf("Elemen terakhir '%s' berhasil dihapus. Neff: %d\n", deletedElement, l.neff);

    // 10. Deallocate ListDin
    printf("\n10. Menghapus ListDin dari memori.\n");
    DeallocateListDin(&l);
    printf("ListDin berhasil dihapus dari memori.\n");

    return 0;
}
