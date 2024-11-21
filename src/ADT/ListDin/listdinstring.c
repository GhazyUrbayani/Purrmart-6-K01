#include "listdinstring.h"
#include <stdlib.h>
#include <stdio.h>
# include <string.h>
// Digunakan untuk menyimpan data dengan kapasitas fleksibel, seperti daftar barang atau akun.

/* Membuat ListDin kosong */
/* Alokasikan memori untuk buffer dengan kapasitas tertentu */
void CreateListDin(ListBarang *l, int capacity) {
    l->barang = (Barang *)malloc(capacity * sizeof(Barang));
    l->capacity = capacity;
    l->neff = 0;
}

/* Menghapus ListDin dari memori */
/* Bebaskan memori buffer dan reset kapasitas serta jumlah elemen */
void DeallocateListDin(ListBarang *l) {
    free(l->barang); // Bebaskan buffer array
    l->capacity = 0;
    l->neff = 0;
}

/* Mengecek apakah ListDin kosong */
/* Return true jika tidak ada elemen */
boolean IsEmpty(ListBarang l) {
    return l.neff == 0;
}

/* Mengecek apakah ListDin penuh */
/* Return true jika jumlah elemen mencapai kapasitas */
boolean IsFull(ListBarang l) {
    return l.neff == l.capacity;
}

/* Mendapatkan indeks pertama elemen dalam list */
/* Return IDX_MIN jika tidak kosong, IDX_UNDEF jika kosong */
int GetFirstIdx(ListBarang l) {
    return IsEmpty(l) ? IDX_UNDEF : IDX_MIN;
}

/* Mendapatkan indeks terakhir elemen dalam list */
/* Return indeks terakhir jika tidak kosong, IDX_UNDEF jika kosong */
int GetLastIdx(ListBarang l) {
    return IsEmpty(l) ? IDX_UNDEF : l.neff - 1;
}

/* Menambahkan elemen string di akhir list */
/* Alokasikan memori baru jika penuh, salin Word ke buffer */
void InsertLast(ListBarang *l, Word w, int price) {
    if (IsFull(*l)) {
        int newCapacity = l->capacity * 2;
        l->barang = (Barang *)realloc(l->barang, newCapacity * sizeof(Barang));
        l->capacity = newCapacity;
    }

    for (int i = 0; i < w.Length && i < MAX_LEN - 1; i++) {
        l->barang[l->neff].name[i] = w.TabWord[i];
    }
    l->barang[l->neff].name[w.Length] = '\0';
    l->barang[l->neff].price = price;
    l->neff++;
}

/* Menghapus elemen terakhir dari list */
/* Hapus elemen terakhir dan simpan string-nya di val */
void DeleteLast(ListBarang *l, Barang *val) {
    if (!IsEmpty(*l)) {
        *val = l->barang[--l->neff];
    }
}

/* Menghapus elemen pada indeks tertentu */
/* Geser elemen setelah indeks untuk mengisi celah */
void DeleteAt(ListBarang *l, int idx, Barang *val) {
    if (idx >= IDX_MIN && idx < l->neff) {
        *val = l->barang[idx];
        for (int i = idx; i < l->neff - 1; i++) {
            l->barang[i] = l->barang[i + 1];
        }
        l->neff--;
    }
}

/* Mencari indeks elemen dalam list */
/* Return indeks pertama yang sesuai dengan Word, IDX_UNDEF jika tidak ditemukan */
int indexOfDin(ListBarang l, Word w) {
    for (int i = 0; i < l.neff; i++) {
        boolean match = true;
        for (int j = 0; j < w.Length; j++) {
            if (w.TabWord[j] != l.barang[i].name[j]) {
                match = false;
                break;
            }
        }
        if (match && l.barang[i].name[w.Length] == '\0') {
            return i;
        }
    }
    return IDX_UNDEF;
}

/* Mengurutkan elemen dalam list */
/* Sorting elemen secara ascending atau descending */
void sortDin(ListBarang *l, boolean ascending) {
    for (int i = 0; i < l->neff - 1; i++) {
        for (int j = i + 1; j < l->neff; j++) {
            boolean condition = ascending
                ? (strcmp(l->barang[i].name, l->barang[j].name) > 0) 
                : (strcmp(l->barang[i].name, l->barang[j].name) < 0);
            if (condition) {
                Barang temp = l->barang[i];
                l->barang[i] = l->barang[j];
                l->barang[j] = temp;
            }
        }
    }
}

/* Mengompresi kapasitas list */
/* Sesuaikan kapasitas buffer dengan jumlah elemen efektif */
void compressListDin(ListBarang *l) {
    l->barang = (Barang *)realloc(l->barang, l->neff * sizeof(Barang));
    l->capacity = l->neff;
}
