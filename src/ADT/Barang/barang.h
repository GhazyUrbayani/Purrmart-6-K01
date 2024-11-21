#ifndef BARANG_H
#define BARANG_H

#include "./../boolean.h"
#include "./../Mesin Kata/mesinkata.h" 

#define MAX_LEN 50 // Panjang maksimum untuk nama barang

typedef struct {
    char name[MAX_LEN]; // Nama barang
    int price;          // Harga barang
} Barang;

/* *** Konstruktor *** */
/**
 * Membuat Barang baru dengan atribut yang diberikan.
 * IS: Barang belum terinisialisasi.
 * FS: Barang terinisialisasi dengan nama dan harga.
 */
void CreateBarang(Barang *b, char name[], int price);

/* *** Fungsi dan Operasi *** */
/**
 * Mengecek apakah dua Barang sama berdasarkan nama.
 * IS: Kedua Barang valid.
 * FS: Tidak ada perubahan.
 * Return: true jika nama sama, false jika tidak.
 */
boolean IsSameBarang(Barang b1, Barang b2);

/**
 * Menghapus data Barang dengan mengosongkan atribut-atributnya.
 * IS: Barang valid dan terinisialisasi.
 * FS: Atribut Barang di-set menjadi kosong atau default.
 */
void DeleteBarang(Barang *b);

#endif
