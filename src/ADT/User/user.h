#ifndef USER_H
#define USER_H

#include "../boolean.h"
#include "../mesinkata.h" // Menggunakan fungsi salinan string dari MesinKata

#define MAX_LEN 100 // Panjang maksimum untuk nama dan password

typedef struct {
    char name[MAX_LEN];      // Nama pengguna
    char password[MAX_LEN];  // Password pengguna
    int money;               // Jumlah uang pengguna
} User;

/* *** Konstruktor *** */
/**
 * Membuat User baru dengan atribut yang diberikan.
 * IS: User belum terinisialisasi.
 * FS: User terinisialisasi dengan nama, password, dan uang.
 */
void CreateUser(User *u, char name[], char password[], int money);

/* *** Fungsi dan Operasi *** */
/**
 * Mengecek apakah dua User sama berdasarkan nama.
 * IS: Kedua User valid.
 * FS: Tidak ada perubahan.
 * Return: true jika nama sama, false jika tidak.
 */
boolean IsSameUser(User u1, User u2);

/**
 * Menghapus data User dengan mengosongkan atribut-atributnya.
 * IS: User valid dan terinisialisasi.
 * FS: Atribut User di-set menjadi kosong atau default.
 */
void DeleteUser(User *u);

#endif
