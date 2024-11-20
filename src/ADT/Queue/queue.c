#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
// Cocok untuk mengelola data yang bersifat antrian (FIFO), seperti permintaan barang pada toko

/* Membuat Queue kosong */
void CreateQueue(Queue *q) {
    q->head = IDX_UNDEF;
    q->tail = IDX_UNDEF;
}

/* Mengecek apakah Queue kosong */
boolean IsEmpty(Queue q) {
    return q.head == IDX_UNDEF;
}

/* Mengecek apakah Queue penuh */
boolean IsFull(Queue q) {
    return ((q.tail + 1) % CAPACITY) == q.head;
}

/* Menambahkan elemen ke dalam Queue */
void Enqueue(Queue *q, ElType val) {
    if (!IsFull(*q)) {
        if (IsEmpty(*q)) {
            q->head = q->tail = 0;
        } else {
            q->tail = (q->tail + 1) % CAPACITY;
        }
        q->buffer[q->tail] = val;
    } else {
        printf("Queue penuh, tidak dapat menambahkan elemen.\n");
    }
}

/* Menghapus elemen dari Queue */
void Dequeue(Queue *q, ElType *val) {
    if (!IsEmpty(*q)) {
        *val = q->buffer[q->head];
        if (q->head == q->tail) {
            q->head = q->tail = IDX_UNDEF;
        } else {
            q->head = (q->head + 1) % CAPACITY;
        }
    } else {
        printf("Queue kosong, tidak ada elemen untuk dihapus.\n");
    }
}

/* Mengecek apakah elemen ada dalam Queue */
boolean isInQueue(Queue q, ElType val) {
    if (IsEmpty(q)) return false;
    int i = q.head;
    while (1) {
        if (q.buffer[i] == val) return true;
        if (i == q.tail) break;
        i = (i + 1) % CAPACITY;
    }
    return false;
}

/* Menampilkan isi Queue */
void displayQueue(Queue q) {
    if (IsEmpty(q)) {
        printf("Queue kosong.\n");
    } else {
        int i = q.head;
        while (1) {
            printf("%d ", q.buffer[i]);
            if (i == q.tail) break;
            i = (i + 1) % CAPACITY;
        }
        printf("\n");
    }
}
