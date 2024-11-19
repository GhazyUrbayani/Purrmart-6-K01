#include "listdin.h"
#include <stdlib.h>
#include <stdio.h>
// Digunakan untuk menyimpan data dengan kapasitas fleksibel, seperti daftar barang atau akun.

/* Membuat list dinamis kosong */
void CreateListDin(ListDin *l, int capacity) {
    // Alokasi memori untuk array dinamis
    l->buffer = (int *)malloc(capacity * sizeof(int));
    l->capacity = capacity;
    l->neff = 0; // Awalnya kosong
}

/* Menghapus list dinamis dari memori */
void DeallocateListDin(ListDin *l) {
    // Bebaskan memori dan reset atribut
    free(l->buffer);
    l->capacity = 0;
    l->neff = 0;
}

/* Mengecek apakah list kosong */
bool IsEmpty(ListDin l) {
    return l.neff == 0; // true jika tidak ada elemen
}

/* Mengecek apakah list penuh */
bool IsFull(ListDin l) {
    return l.neff == l.capacity; // true jika neff == kapasitas
}

/* Menambahkan elemen di akhir list */
void InsertLast(ListDin *l, int val) {
    if (IsFull(*l)) {
        int newCapacity = l->capacity * 2;
        l->buffer = (int *)realloc(l->buffer, newCapacity * sizeof(int));
        l->capacity = newCapacity;
    }
    l->buffer[l->neff++] = val;
}

/* Menghapus elemen di akhir list */
void DeleteLast(ListDin *l, int *val) {
    if (!IsEmpty(*l)) {
        // Ambil elemen terakhir dan kurangi neff
        *val = l->buffer[--l->neff];
    }
}

/* Menghapus elemen pertama dari list */
void DeleteFirst(ListDin *l, int *val) {
    if (!IsEmpty(*l)) {
        *val = l->buffer[0];
        for (int i = 0; i < l->neff - 1; i++) {
            l->buffer[i] = l->buffer[i + 1];
        }
        l->neff--;
    }
}

/* Mencari indeks elemen di list */
int Find(ListDin l, int val) {
    for (int i = 0; i < l.neff; i++) {
        if (l.buffer[i] == val) {
            return i; // Elemen ditemukan
        }
    }
    return IDX_UNDEF; // Elemen tidak ditemukan
}
