#include "liststatuser.h"

/* Membuat list statis kosong */
void CreateListStatUser(ListStatUser *l) {
    l->neff = 0;
}

/* Mengecek apakah list kosong */
boolean IsEmptyUser(ListStatUser l) {
    return l.neff == 0;
}

/* Mengecek apakah list penuh */
boolean IsFullUser(ListStatUser l) {
    return l.neff == CAPACITY;
}

/* Menambahkan elemen baru di akhir list */
void InsertLastUser(ListStatUser *l, ElType val) {
    if (!IsFullUser(*l)) {
        l->buffer[l->neff] = val;
        l->neff++;
    }
}

/* Menghapus elemen terakhir dari list */
void DeleteLastUser(ListStatUser *l, ElType *val) {
    if (!IsEmptyUser(*l)) {
        *val = l->buffer[l->neff - 1];
        l->neff--;
    }
}
