#ifndef QUEUE_H
#define QUEUE_H
// Cocok untuk mengelola data yang bersifat antrian (FIFO), seperti permintaan barang pada toko

#include <stdbool.h>

#define CAPACITY 100
#define IDX_UNDEF -1

typedef int ElType;
typedef struct {
    ElType buffer[CAPACITY]; // Array untuk menyimpan elemen queue
    int head;                // Indeks elemen pertama (head)
    int tail;                // Indeks elemen terakhir (tail)
} Queue;

/* *** Konstruktor dan Destruktor *** */
/**
 * Membuat queue kosong.
 * Initial State: Queue tidak terdefinisi (head dan tail belum diinisialisasi).
 * Final State: Queue kosong dengan head dan tail di IDX_UNDEF.
 * Parameter:
 *   - q: pointer ke Queue yang akan diinisialisasi.
 */
void CreateQueue(Queue *q);

/* *** Fungsi dan Operasi *** */
/**
 * Mengecek apakah queue kosong.
 * Initial State: Queue valid.
 * Final State: Tidak ada perubahan pada Queue.
 * Parameter:
 *   - q: Queue yang diperiksa.
 * Return:
 *   - true jika queue kosong, false jika tidak.
 */
bool IsEmpty(Queue q);

/**
 * Mengecek apakah queue penuh.
 * Initial State: Queue valid.
 * Final State: Tidak ada perubahan pada Queue.
 * Parameter:
 *   - q: Queue yang diperiksa.
 * Return:
 *   - true jika queue penuh, false jika tidak.
 */
bool IsFull(Queue q);

/**
 * Menambahkan elemen baru ke akhir queue.
 * Initial State: Queue tidak penuh.
 * Final State: Elemen baru ditambahkan pada tail, dan tail bergerak ke posisi berikutnya (modular).
 * Parameter:
 *   - q: pointer ke Queue tempat elemen akan ditambahkan.
 *   - val: nilai elemen yang akan ditambahkan.
 */
void Enqueue(Queue *q, ElType val);

/**
 * Menghapus elemen dari depan queue.
 * Initial State: Queue tidak kosong.
 * Final State: Elemen pada head dihapus, dan head bergerak ke posisi berikutnya (modular).
 * Parameter:
 *   - q: pointer ke Queue tempat elemen akan dihapus.
 *   - val: pointer ke ElType untuk menyimpan elemen yang dihapus.
 */
void Dequeue(Queue *q, ElType *val);

#endif
