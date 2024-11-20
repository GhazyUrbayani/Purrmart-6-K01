#ifndef QUEUE_H
#define QUEUE_H

#include "../boolean.h"

#define CAPACITY 100    // Kapasitas maksimum queue
#define IDX_UNDEF -1    // Indeks tak terdefinisi

typedef int ElType;     // Tipe elemen queue (bisa diubah sesuai kebutuhan, misalnya struct Barang)

typedef struct {
    ElType buffer[CAPACITY]; // Array untuk menyimpan elemen queue
    int head;                // Indeks elemen pertama (head)
    int tail;                // Indeks elemen terakhir (tail)
} Queue;

/* *** Konstruktor dan Destruktor *** */
void CreateQueue(Queue *q);

/* *** Fungsi dan Validasi *** */
boolean IsEmpty(Queue q);
boolean IsFull(Queue q);

/* *** Operasi Queue *** */
void Enqueue(Queue *q, ElType val);
void Dequeue(Queue *q, ElType *val);

/* *** Fungsi Tambahan *** */
boolean isInQueue(Queue q, ElType val);
void displayQueue(Queue q);

#endif
