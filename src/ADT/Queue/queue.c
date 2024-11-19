#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
// Cocok untuk mengelola data yang bersifat antrian (FIFO), seperti permintaan barang pada toko

/* Membuat Queue kosong */
void CreateQueue(Queue *q) {
    q->head = IDX_UNDEF;
    q->tail = IDX_UNDEF;
    // Reminder: Inisialisasi awal untuk Queue kosong atau head dan tail tidak terdefinisi
}

/* Mengecek apakah Queue kosong */
bool IsEmpty(Queue q) {
    return q.head == IDX_UNDEF; // true jika queue kosong
    // Reminder: Head dan tail tidak menunjuk ke elemen apa pun
}

/* Mengecek apakah Queue penuh */
bool IsFull(Queue q) {
    // true jika posisi berikutnya dari tail adalah head
    return ((q.tail + 1) % CAPACITY) == q.head;
    // Reminder: Jika indeks berikutnya dari tail adalah head, berarti Queue penuh
}

/* Menambahkan elemen ke akhir Queue */
void Enqueue(Queue *q, ElType val) {
    if (!IsFull(*q)) {
        if (IsEmpty(*q)) {
            // Jika kosong, head dan tail di posisi awal
            q->head = q->tail = 0;
        } else {
            // Tambahkan elemen pada posisi tail baru
            q->tail = (q->tail + 1) % CAPACITY;
        }
        q->buffer[q->tail] = val;
        // Reminder: Tail diperbarui, elemen ditambahkan ke posisi tail
    }
}

/* Menghapus elemen dari awal Queue */
void Dequeue(Queue *q, ElType *val) {
    if (!IsEmpty(*q)) {
        *val = q->buffer[q->head]; // Ambil elemen di head
        if (q->head == q->tail) {
            // Jika hanya satu elemen, kosongkan queue
            q->head = q->tail = IDX_UNDEF;
            // Reminder: Queue menjadi kosong
        } else {
            // Geser head ke posisi berikutnya
            q->head = (q->head + 1) % CAPACITY;
            // Reminder: Head diperbarui ke elemen berikutnya
        }
    }
}
