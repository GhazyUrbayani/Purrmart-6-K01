#ifndef STACK_H
#define STACK_H
//Ideal untuk menyimpan riwayat data (LIFO), seperti riwayat tebakan pada game

#include <stdbool.h>

#define CAPACITY 100

typedef int ElType;
typedef struct {
    ElType buffer[CAPACITY]; // Array untuk menyimpan elemen stack
    int top;                 // Indeks elemen teratas stack
} Stack;

/* *** Konstruktor *** */
/**
 * Membuat stack kosong.
 * Initial State: Stack tidak terdefinisi (top belum diinisialisasi).
 * Final State: Stack kosong dengan top = -1.
 * Parameter:
 *   - s: pointer ke Stack yang akan diinisialisasi.
 */
void CreateStack(Stack *s);

/* *** Fungsi dan Operasi *** */
/**
 * Mengecek apakah stack kosong.
 * Initial State: Stack valid.
 * Final State: Tidak ada perubahan pada Stack.
 * Parameter:
 *   - s: Stack yang diperiksa.
 * Return:
 *   - true jika stack kosong, false jika tidak.
 */
bool IsEmpty(Stack s);

/**
 * Mengecek apakah stack penuh.
 * Initial State: Stack valid.
 * Final State: Tidak ada perubahan pada Stack.
 * Parameter:
 *   - s: Stack yang diperiksa.
 * Return:
 *   - true jika stack penuh, false jika tidak.
 */
bool IsFull(Stack s);

/**
 * Menambahkan elemen baru ke atas stack.
 * Initial State: Stack tidak penuh.
 * Final State: Elemen baru ditambahkan pada indeks top+1, dan top bertambah 1.
 * Parameter:
 *   - s: pointer ke Stack tempat elemen akan ditambahkan.
 *   - val: nilai elemen yang akan ditambahkan.
 */
void Push(Stack *s, ElType val);

/**
 * Menghapus elemen dari atas stack.
 * Initial State: Stack tidak kosong.
 * Final State: Elemen pada indeks top dihapus, dan top berkurang 1.
 * Parameter:
 *   - s: pointer ke Stack tempat elemen akan dihapus.
 *   - val: pointer ke ElType untuk menyimpan elemen yang dihapus.
 */
void Pop(Stack *s, ElType *val);

#endif
