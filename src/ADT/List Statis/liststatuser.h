#ifndef LISTSTATUSER_H
#define LISTSTATUSER_H

#include "../boolean.h"
#include "../User/user.h"

/* Definisi ukuran maksimum list */
#define MAX_USER 100
#define IDX_UNDEF -1

typedef struct {
    User users[MAX_USER]; 
    int neff;
} ListUser;
/* *** Konstruktor *** */
/**
 * Membuat list statis kosong.
 * IS: List belum terdefinisi.
 * FS: List terdefinisi dengan jumlah elemen efektif = 0.
 */
void CreateListStatUser(ListUser *l);

/* *** Fungsi dan Validasi *** */
/**
 * Mengecek apakah list kosong.
 * IS: List valid.
 * FS: Tidak ada perubahan pada list.
 * Return: true jika list kosong (neff = 0), false jika tidak.
 */
boolean IsEmptyUser(ListUser l);

/**
 * Mengecek apakah list penuh.
 * IS: List valid.
 * FS: Tidak ada perubahan pada list.
 * Return: true jika list penuh (neff = CAPACITY), false jika tidak.
 */
boolean IsFullUser(ListUser l);

/* *** Operasi Dasar ListStatUser *** */
/**
 * Menambahkan elemen baru di akhir list.
 * IS: List valid, tidak penuh.
 * FS: Elemen baru ditambahkan di akhir list.
 */
void InsertLastUser(ListUser *l, User val);

/**
 * Menghapus elemen terakhir dari list.
 * IS: List valid, tidak kosong.
 * FS: Elemen terakhir dihapus.
 */
void DeleteLastUser(ListUser *l, User *val);

#endif
