#ifndef LISTDIN_H
#define LISTDIN_H
// Digunakan untuk menyimpan data dengan kapasitas fleksibel, seperti daftar barang atau akun.

#include <stdlib.h>
#include "../mesinkata.h"
#include "../boolean.h"

/* Definisi kapasitas maksimum elemen string */
#define NMax 150

/* Definisi tipe elemen berupa string */
typedef char* ElType;

/* Definisi struktur ListDin */
typedef struct {
    ElType *buffer; // Array dinamis untuk menyimpan elemen
    int capacity;   // Kapasitas maksimum list
    int neff;       // Jumlah elemen efektif
} ListDin;

/* *** Konstruktor dan Destruktor *** */
void CreateListDin(ListDin *l, int capacity);
/* IS: List belum teralokasi */
/* FS: List dialokasikan dengan kapasitas `capacity` dan elemen kosong */

void DeallocateListDin(ListDin *l);
/* IS: List teralokasi */
/* FS: List dibebaskan dari memori, termasuk semua elemen */

/* *** Fungsi dan Validasi *** */
boolean IsEmpty(ListDin l);
/* Mengembalikan true jika list kosong */

boolean IsFull(ListDin l);
/* Mengembalikan true jika list penuh */

/* *** Operasi ListDin *** */
void InsertLast(ListDin *l, ElType val);
/* IS: List teralokasi */
/* FS: Elemen `val` ditambahkan di akhir list. Jika penuh, kapasitas diperbesar */

void DeleteLast(ListDin *l, ElType *val);
/* IS: List tidak kosong */
/* FS: Elemen terakhir dihapus dan disimpan di `val` */

int Find(ListDin l, ElType val);
/* IS: List teralokasi */
/* FS: Mengembalikan indeks elemen pertama yang sama dengan `val` (case-sensitive),
       atau -1 jika tidak ditemukan */

#endif
