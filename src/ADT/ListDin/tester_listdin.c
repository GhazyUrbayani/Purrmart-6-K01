#include "listdinstring.h"
#include <stdlib.h>
#include <stdio.h>
// ListDin: Memastikan list dinamis dapat ditambahkan, dihapus, dan dicari elemen dengan benar

int main() {
    // Variabel untuk pengujian
    ListDin l;
    Word w1 = {"Apple", 5};
    Word w2 = {"Banana", 6};
    Word w3 = {"Cherry", 6};
    ElType deletedElement;
    
    // 1. Buat list dinamis dengan kapasitas awal 2
    printf("1. Membuat ListDin dengan kapasitas awal 2.\n");
    CreateListDin(&l, 2);
    printf("ListDin berhasil dibuat. Kapasitas: %d, Neff: %d\n", l.capacity, l.neff);
    
    // 2. Tambahkan elemen ke list
    printf("\n2. Menambahkan elemen ke ListDin.\n");
    InsertLast(&l, w1);
    InsertLast(&l, w2);
    printf("Elemen berhasil ditambahkan. Neff: %d\n", l.neff);
    printf("Isi List: [%s, %s]\n", l.buffer[0], l.buffer[1]);
    
    // 3. Perbesar kapasitas otomatis
    printf("\n3. Menambahkan elemen untuk memicu expand.\n");
    InsertLast(&l, w3);
    printf("Elemen berhasil ditambahkan. Kapasitas: %d, Neff: %d\n", l.capacity, l.neff);
    printf("Isi List: [%s, %s, %s]\n", l.buffer[0], l.buffer[1], l.buffer[2]);
    
    // 4. Cari elemen
    printf("\n4. Mencari elemen 'Banana' di ListDin.\n");
    int idx = indexOfDin(l, w2);
    if (idx != IDX_UNDEF) {
        printf("Elemen ditemukan di indeks: %d\n", idx);
    } else {
        printf("Elemen tidak ditemukan.\n");
    }
    
    // 5. Hapus elemen terakhir
    printf("\n5. Menghapus elemen terakhir dari ListDin.\n");
    DeleteLast(&l, &deletedElement);
    printf("Elemen terakhir '%s' berhasil dihapus. Neff: %d\n", deletedElement, l.neff);
    
    // 6. Urutkan elemen secara ascending
    printf("\n6. Mengurutkan elemen secara ascending.\n");
    sortDin(&l, true);
    printf("Isi List setelah sorting ascending: [%s, %s]\n", l.buffer[0], l.buffer[1]);
    
    // 7. Kompres kapasitas
    printf("\n7. Mengompresi kapasitas ListDin.\n");
    compressListDin(&l);
    printf("ListDin berhasil dikompresi. Kapasitas: %d, Neff: %d\n", l.capacity, l.neff);
    
    // 8. Deallocate ListDin
    printf("\n8. Menghapus ListDin dari memori.\n");
    DeallocateListDin(&l);
    printf("ListDin berhasil dihapus dari memori.\n");

    return 0;
}
