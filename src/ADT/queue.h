#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

#define QUEUE_MAX 100 // Kapasitas maksimal queue

typedef struct {
    void *items[QUEUE_MAX]; // Array elemen dalam queue
    size_t itemSizes[QUEUE_MAX]; // Ukuran masing-masing elemen
    size_t front; // Indeks elemen terdepan
    size_t rear; // Indeks elemen terakhir
    size_t size; // Jumlah elemen dalam queue
} Queue;

// Prototipe fungsi
void initQueue(Queue *queue);
int isQueueEmpty(Queue *queue);
int isQueueFull(Queue *queue);
void enqueue(Queue *queue, void *item, size_t itemSize);
void* dequeue(Queue *queue);
void* peekQueue(Queue *queue);
void clearQueue(Queue *queue);

#endif
