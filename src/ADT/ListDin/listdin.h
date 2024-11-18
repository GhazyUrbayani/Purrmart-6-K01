#ifndef LISTDIN_H
#define LISTDIN_H
// Digunakan untuk menyimpan data dengan kapasitas fleksibel, seperti daftar barang atau akun.

#include <stdbool.h>

/* Indeks tidak terdefinisi */
#define IDX_UNDEF -1
/* Nilai default untuk elemen yang tidak valid */
#define VAL_UNDEF -999

/* Definisi tipe data ListDin */
typedef struct {
    int *buffer;    // Pointer ke array dinamis
    int capacity;   // Kapasitas maksimum list
    int neff;       // Jumlah elemen efektif
} ListDin;

/* *** Konstruktor dan Destruktor *** */
/**
 * Membuat list dinamis kosong dengan kapasitas tertentu.
 * Initial State: ListDin belum dialokasikan memori.
 * Final State: ListDin memiliki buffer yang dapat menampung 'capacity' elemen, dan 'neff' bernilai 0.
 * Parameter:
 *   - l: pointer ke ListDin yang akan dibuat.
 *   - capacity: kapasitas maksimum list.
 */
void CreateListDin(ListDin *l, int capacity);

/**
 * Menghapus list dinamis dari memori.
 * Initial State: ListDin telah dialokasikan.
 * Final State: Memori buffer ListDin dibebaskan, dan kapasitas serta jumlah elemen efektif diatur menjadi 0.
 * Parameter:
 *   - l: pointer ke ListDin yang akan dihapus.
 */
void DeallocateListDin(ListDin *l);

/* *** Fungsi-fungsi Validasi *** */
/**
 * Mengecek apakah list dinamis kosong.
 * Initial State: ListDin valid.
 * Final State: Tidak ada perubahan pada ListDin.
 * Parameter:
 *   - l: ListDin yang diperiksa.
 * Return:
 *   - true jika list kosong (neff == 0), false jika tidak.
 */
bool IsEmpty(ListDin l);

/**
 * Mengecek apakah list dinamis penuh.
 * Initial State: ListDin valid.
 * Final State: Tidak ada perubahan pada ListDin.
 * Parameter:
 *   - l: ListDin yang diperiksa.
 * Return:
 *   - true jika list penuh (neff == capacity), false jika tidak.
 */
bool IsFull(ListDin l);

/* *** Operasi ListDin *** */
/**
 * Menambahkan elemen di akhir list.
 * Initial State: ListDin tidak penuh.
 * Final State: Elemen baru ditambahkan pada indeks ke-neff, dan nilai neff bertambah 1.
 * Parameter:
 *   - l: pointer ke ListDin tempat elemen akan ditambahkan.
 *   - val: nilai elemen yang akan ditambahkan.
 */
void InsertLast(ListDin *l, int val);

/**
 * Menghapus elemen di akhir list.
 * Initial State: ListDin tidak kosong.
 * Final State: Elemen terakhir dihapus dari list, dan nilai neff berkurang 1.
 * Parameter:
 *   - l: pointer ke ListDin tempat elemen akan dihapus.
 *   - val: pointer ke integer untuk menyimpan elemen yang dihapus.
 */
void DeleteLast(ListDin *l, int *val);

/**
 * Mencari indeks elemen dengan nilai tertentu di list.
 * Initial State: ListDin valid.
 * Final State: Tidak ada perubahan pada ListDin.
 * Parameter:
 *   - l: ListDin tempat pencarian dilakukan.
 *   - val: nilai elemen yang dicari.
 * Return:
 *   - Indeks elemen jika ditemukan, IDX_UNDEF jika tidak.
 */
int Find(ListDin l, int val);

#endif
