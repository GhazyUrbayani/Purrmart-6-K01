#ifndef LISTDIN_H
#define LISTDIN_H
// Digunakan untuk menyimpan data dengan kapasitas fleksibel, seperti daftar barang atau akun.

#include <stdlib.h>
#include "../Mesin Kata/mesinkata.h"
#include "../Barang/barang.h"
#include "../boolean.h"

/*  Kamus Umum */
#define IDX_MIN 0
#define IDX_UNDEF -1

typedef struct {
    Barang *barang;  // Pointer ke array dinamis untuk menyimpan barang
    int capacity;    // Kapasitas maksimum list
    int neff;        // Jumlah elemen efektif
} ListBarang;

/* *** Konstruktor dan Destruktor *** */

/**
 * Membuat ListDin kosong.
 * Initial State: List belum teralokasi (pointer buffer tidak valid).
 * Final State: List teralokasi dengan kapasitas `capacity`, elemen kosong (neff = 0).
 * Parameter:
 *   - l: Pointer ke ListDin yang akan dibuat.
 *   - capacity: Kapasitas awal list.
 */
void CreateListDin(ListBarang *l, int capacity);

/**
 * Menghapus ListDin dari memori.
 * Initial State: List teralokasi dan berisi sejumlah elemen (neff >= 0).
 * Final State: List dibebaskan dari memori (pointer buffer = NULL, capacity = 0, neff = 0).
 * Parameter:
 *   - l: Pointer ke ListDin yang akan dihapus.
 */
void DeallocateListDin(ListBarang *l);

/* *** Fungsi dan Validasi *** */

/**
 * Mengecek apakah ListDin kosong.
 * Initial State: List valid (teralokasi).
 * Final State: Tidak ada perubahan pada list.
 * Parameter:
 *   - l: ListDin yang diperiksa.
 * Return:
 *   - true jika list kosong (neff == 0), false jika tidak.
 */
boolean IsEmpty(ListBarang l);

/**
 * Mengecek apakah ListDin penuh.
 * Initial State: List valid (teralokasi).
 * Final State: Tidak ada perubahan pada list.
 * Parameter:
 *   - l: ListDin yang diperiksa.
 * Return:
 *   - true jika list penuh (neff == capacity), false jika tidak.
 */
boolean IsFull(ListBarang l);

/**
 * Mengembalikan indeks pertama elemen dalam list.
 * Initial State: List valid (teralokasi).
 * Final State: Tidak ada perubahan pada list.
 * Parameter:
 *   - l: ListDin yang diperiksa.
 * Return:
 *   - Indeks pertama elemen dalam list (IDX_MIN) jika tidak kosong, IDX_UNDEF jika kosong.
 */
int GetFirstIdx(ListBarang l);

/**
 * Mengembalikan indeks terakhir elemen dalam list.
 * Initial State: List valid (teralokasi).
 * Final State: Tidak ada perubahan pada list.
 * Parameter:
 *   - l: ListDin yang diperiksa.
 * Return:
 *   - Indeks terakhir elemen dalam list jika tidak kosong, IDX_UNDEF jika kosong.
 */
int GetLastIdx(ListBarang l);

/* *** Operasi Dasar ListDin *** */

/**
 * Menambahkan elemen string di akhir list.
 * Initial State: List valid (teralokasi), dapat penuh atau tidak penuh.
 * Final State: Elemen `w` ditambahkan ke akhir list. Jika penuh, kapasitas list diperbesar.
 * Parameter:
 *   - l: Pointer ke ListDin tempat elemen akan ditambahkan.
 *   - w: Elemen string berbasis Word yang akan ditambahkan.
 */
void InsertLast(ListBarang *l, Word w, int price);

/**
 * Menghapus elemen terakhir dari list.
 * Initial State: List valid (teralokasi), tidak kosong.
 * Final State: Elemen terakhir dihapus dari list, dan disimpan di `val`.
 * Parameter:
 *   - l: Pointer ke ListDin tempat elemen akan dihapus.
 *   - val: Pointer ke ElType untuk menyimpan elemen yang dihapus.
 */
void DeleteLast(ListBarang *l, Barang *val);

/**
 * Menghapus elemen pada indeks tertentu.
 * Initial State: List valid (teralokasi), tidak kosong, indeks valid.
 * Final State: Elemen pada indeks `idx` dihapus dari list, dan disimpan di `val`.
 * Parameter:
 *   - l: Pointer ke ListDin tempat elemen akan dihapus.
 *   - idx: Indeks elemen yang akan dihapus.
 *   - val: Pointer ke ElType untuk menyimpan elemen yang dihapus.
 */
void DeleteAt(ListBarang *l, int idx, Barang *val);

/* *** Operasi Tambahan *** */

/**
 * Mencari indeks elemen dalam list.
 * Initial State: List valid (teralokasi).
 * Final State: Tidak ada perubahan pada list.
 * Parameter:
 *   - l: ListDin yang diperiksa.
 *   - w: Elemen string berbasis Word yang dicari.
 * Return:
 *   - Indeks elemen pertama yang sama dengan `w`, atau IDX_UNDEF jika tidak ditemukan.
 */
int indexOfDin(ListBarang l, Word w);

/**
 * Mengurutkan elemen dalam list.
 * Initial State: List valid (teralokasi), dapat kosong atau berisi elemen.
 * Final State: Elemen dalam list terurut secara ascending atau descending.
 * Parameter:
 *   - l: Pointer ke ListDin yang akan diurutkan.
 *   - ascending: true untuk ascending, false untuk descending.
 */
void sortDin(ListBarang *l, boolean ascending);

/**
 * Mengompresi kapasitas list agar sesuai dengan jumlah elemen efektif.
 * Initial State: List valid (teralokasi), kapasitas >= neff.
 * Final State: Kapasitas list = neff, elemen tetap.
 * Parameter:
 *   - l: Pointer ke ListDin yang akan dikompresi.
 */
void compressListDin(ListBarang *l);

#endif
