#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

/* Membuat Queue kosong */
void CreateQueue(Queue *q) {
    q->head = IDX_UNDEF;
    q->tail = IDX_UNDEF;
    // Reminder: Inisialisasi awal untuk Queue kosong
}

/* Mengecek apakah Queue kosong */
bool IsEmpty(Queue q) {
    return q.head == IDX_UNDEF;
    // Reminder: Head dan tail tidak menunjuk ke elemen apa pun
}

/* Mengecek apakah Queue penuh */
bool IsFull(Queue q) {
    return ((q.tail + 1) % CAPACITY) == q.head;
    // Reminder: Jika indeks berikutnya dari tail adalah head, berarti Queue penuh
}

/* Menambahkan elemen ke akhir Queue */
void Enqueue(Queue *q, ElType val) {
    if (!IsFull(*q)) {
        if (IsEmpty(*q)) {
            q->head = q->tail = 0;
        } else {
            q->tail = (q->tail + 1) % CAPACITY;
        }
        q->buffer[q->tail] = val;
        // Reminder: Tail diperbarui, elemen ditambahkan ke posisi tail
    }
}

/* Menghapus elemen dari awal Queue */
void Dequeue(Queue *q, ElType *val) {
    if (!IsEmpty(*q)) {
        *val = q->buffer[q->head];
        if (q->head == q->tail) {
            q->head = q->tail = IDX_UNDEF;
            // Reminder: Queue menjadi kosong
        } else {
            q->head = (q->head + 1) % CAPACITY;
            // Reminder: Head diperbarui ke elemen berikutnya
        }
    }
}
