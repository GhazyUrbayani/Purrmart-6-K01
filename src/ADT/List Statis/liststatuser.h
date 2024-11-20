#ifndef LISTSTATUSER_H
#define LISTSTATUSER_H

#include "../boolean.h"
#include "../user.h" // Include definisi struct User

/* Definisi ukuran maksimum list */
#define CAPACITY 100
#define IDX_UNDEF -1

typedef struct User ElType; // Elemen list adalah struct User

typedef struct {
    ElType buffer[CAPACITY]; // Array untuk menyimpan elemen User
    int neff;                // Jumlah elemen efektif
} ListStatUser;

/* *** Konstruktor *** */
/**
 * Membuat list statis kosong.
 * IS: List belum terdefinisi.
 * FS: List terdefinisi dengan jumlah elemen efektif = 0.
 */
void CreateListStatUser(ListStatUser *l);

/* *** Fungsi dan Validasi *** */
/**
 * Mengecek apakah list kosong.
 * IS: List valid.
 * FS: Tidak ada perubahan pada list.
 * Return: true jika list kosong (neff = 0), false jika tidak.
 */
boolean IsEmptyUser(ListStatUser l);

/**
 * Mengecek apakah list penuh.
 * IS: List valid.
 * FS: Tidak ada perubahan pada list.
 * Return: true jika list penuh (neff = CAPACITY), false jika tidak.
 */
boolean IsFullUser(ListStatUser l);

/* *** Operasi Dasar ListStatUser *** */
/**
 * Menambahkan elemen baru di akhir list.
 * IS: List valid, tidak penuh.
 * FS: Elemen baru ditambahkan di akhir list.
 */
void InsertLastUser(ListStatUser *l, ElType val);

/**
 * Menghapus elemen terakhir dari list.
 * IS: List valid, tidak kosong.
 * FS: Elemen terakhir dihapus.
 */
void DeleteLastUser(ListStatUser *l, ElType *val);

#endif
