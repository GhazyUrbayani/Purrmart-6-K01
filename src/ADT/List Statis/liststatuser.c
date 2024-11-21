#include "liststatuser.h"

/* Membuat list statis kosong */
void CreateListStatUser(ListUser *l) {
    l->neff = 0;
}

/* Mengecek apakah list kosong */
boolean IsEmptyUser(ListUser l) {
    return l.neff == 0;
}

/* Mengecek apakah list penuh */
boolean IsFullUser(ListUser l) {
    return l.neff == MAX_USER;
}

/* Menambahkan elemen baru di akhir list */
void InsertLastUser(ListUser *l, User val) {
    if (!IsFullUser(*l)) {
        l->users[l->neff] = val;
        l->neff++;
    }
}

/* Menghapus elemen terakhir dari list */
void DeleteLastUser(ListUser *l, User *val) {
    if (!IsEmptyUser(*l)) {
        *val = l->users[l->neff - 1];
        l->neff--;
    }
}
