#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
// Cocok untuk mengelola data yang bersifat antrian (FIFO), seperti permintaan barang pada toko

/* Membuat queue kosong */
void CreateQueue(Queue *q) {
    // Inisialisasi head dan tail tidak terdefinisi
    q->head = IDX_UNDEF;
    q->tail = IDX_UNDEF;
}

/* Mengecek apakah queue kosong */
bool IsEmpty(Queue q) {
    return q.head == IDX_UNDEF; // true jika queue kosong
}

/* Mengecek apakah queue penuh */
bool IsFull(Queue q) {
    // true jika posisi berikutnya dari tail adalah head
    return ((q.tail + 1) % CAPACITY) == q.head;
}

/* Menambahkan elemen ke akhir queue */
void Enqueue(Queue *q, ElType val) {
    if (IsEmpty(*q)) {
        // Jika kosong, head dan tail di posisi awal
        q->head = q->tail = 0;
    } else {
        // Tambahkan elemen pada posisi tail baru
        q->tail = (q->tail + 1) % CAPACITY;
    }
    q->buffer[q->tail] = val;
}

/* Menghapus elemen dari depan queue */
void Dequeue(Queue *q, ElType *val) {
    *val = q->buffer[q->head]; // Ambil elemen di head
    if (q->head == q->tail) {
        // Jika hanya satu elemen, kosongkan queue
        q->head = q->tail = IDX_UNDEF;
    } else {
        // Geser head ke posisi berikutnya
        q->head = (q->head + 1) % CAPACITY;
    }
}
