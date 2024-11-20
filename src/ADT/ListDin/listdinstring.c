#include "listdinstring.h"
#include <stdlib.h>
#include <stdio.h>
// Digunakan untuk menyimpan data dengan kapasitas fleksibel, seperti daftar barang atau akun.

/* Membuat ListDin kosong */
/* Alokasikan memori untuk buffer dengan kapasitas tertentu */
void CreateListDin(ListDin *l, int capacity) {
    l->buffer = (ElType *)malloc(capacity * sizeof(ElType));
    l->capacity = capacity;
    l->neff = 0;
}

/* Menghapus ListDin dari memori */
/* Bebaskan memori buffer dan reset kapasitas serta jumlah elemen */
void DeallocateListDin(ListDin *l) {
    for (int i = 0; i < l->neff; i++) {
        free(l->buffer[i]); // Bebaskan setiap string
    }
    free(l->buffer); // Bebaskan buffer array
    l->capacity = 0;
    l->neff = 0;
}

/* Mengecek apakah ListDin kosong */
/* Return true jika tidak ada elemen */
boolean IsEmpty(ListDin l) {
    return l.neff == 0;
}

/* Mengecek apakah ListDin penuh */
/* Return true jika jumlah elemen mencapai kapasitas */
boolean IsFull(ListDin l) {
    return l.neff == l.capacity;
}

/* Mendapatkan indeks pertama elemen dalam list */
/* Return IDX_MIN jika tidak kosong, IDX_UNDEF jika kosong */
int GetFirstIdx(ListDin l) {
    return IsEmpty(l) ? IDX_UNDEF : IDX_MIN;
}

/* Mendapatkan indeks terakhir elemen dalam list */
/* Return indeks terakhir jika tidak kosong, IDX_UNDEF jika kosong */
int GetLastIdx(ListDin l) {
    return IsEmpty(l) ? IDX_UNDEF : l.neff - 1;
}

/* Menambahkan elemen string di akhir list */
/* Alokasikan memori baru jika penuh, salin Word ke buffer */
void InsertLast(ListDin *l, Word w) {
    if (IsFull(*l)) {
        int newCapacity = l->capacity * 2;
        l->buffer = (ElType *)realloc(l->buffer, newCapacity * sizeof(ElType));
        l->capacity = newCapacity;
    }

    l->buffer[l->neff] = (char *)malloc((w.Length + 1) * sizeof(char));
    for (int i = 0; i < w.Length; i++) {
        l->buffer[l->neff][i] = w.TabWord[i];
    }
    l->buffer[l->neff][w.Length] = '\0';
    l->neff++;
}

/* Menghapus elemen terakhir dari list */
/* Hapus elemen terakhir dan simpan string-nya di val */
void DeleteLast(ListDin *l, ElType *val) {
    if (!IsEmpty(*l)) {
        *val = l->buffer[--l->neff];
    }
}

/* Menghapus elemen pada indeks tertentu */
/* Geser elemen setelah indeks untuk mengisi celah */
void DeleteAt(ListDin *l, int idx, ElType *val) {
    if (idx >= IDX_MIN && idx < l->neff) {
        *val = l->buffer[idx];
        for (int i = idx; i < l->neff - 1; i++) {
            l->buffer[i] = l->buffer[i + 1];
        }
        l->neff--;
    }
}

/* Mencari indeks elemen dalam list */
/* Return indeks pertama yang sesuai dengan Word, IDX_UNDEF jika tidak ditemukan */
int indexOfDin(ListDin l, Word w) {
    for (int i = 0; i < l.neff; i++) {
        boolean match = true;
        for (int j = 0; j < w.Length; j++) {
            if (w.TabWord[j] != l.buffer[i][j]) {
                match = false;
                break;
            }
        }
        if (match && l.buffer[i][w.Length] == '\0') {
            return i;
        }
    }
    return IDX_UNDEF;
}

/* Mengurutkan elemen dalam list */
/* Sorting elemen secara ascending atau descending */
void sortDin(ListDin *l, boolean ascending) {
    for (int i = 0; i < l->neff - 1; i++) {
        for (int j = i + 1; j < l->neff; j++) {
            boolean condition = ascending
                                ? (l->buffer[i][0] > l->buffer[j][0])
                                : (l->buffer[i][0] < l->buffer[j][0]);
            if (condition) {
                ElType temp = l->buffer[i];
                l->buffer[i] = l->buffer[j];
                l->buffer[j] = temp;
            }
        }
    }
}

/* Mengompresi kapasitas list */
/* Sesuaikan kapasitas buffer dengan jumlah elemen efektif */
void compressListDin(ListDin *l) {
    l->buffer = (ElType *)realloc(l->buffer, l->neff * sizeof(ElType));
    l->capacity = l->neff;
}
