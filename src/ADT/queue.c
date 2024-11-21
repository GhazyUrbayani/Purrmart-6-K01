#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "utils.h"

void initQueue(Queue *queue) {
    queue->front = 0;
    queue->rear = QUEUE_MAX - 1;
    queue->size = 0;
}

int isQueueEmpty(Queue *queue) {
    return queue->size == 0;
}

int isQueueFull(Queue *queue) {
    return queue->size == QUEUE_MAX;
}

void enqueue(Queue *queue, void *item, size_t itemSize) {
    if (isQueueFull(queue)) {
        printf("Queue penuh, tidak dapat enqueue.\n");
        return;
    }
    queue->rear = (queue->rear + 1) % QUEUE_MAX;
    queue->items[queue->rear] = alokasi_salin(item, itemSize);
    queue->itemSizes[queue->rear] = itemSize;
    queue->size++;
}

void* dequeue(Queue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue kosong, tidak dapat dequeue.\n");
        return NULL;
    }
    void *item = queue->items[queue->front];
    queue->front = (queue->front + 1) % QUEUE_MAX;
    queue->size--;
    return item;
} // Pemanggil fungsi harus free()

void* peekQueue(Queue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue kosong, tidak dapat peek.\n");
        return NULL;
    }
    return queue->items[queue->front];
}

void clearQueue(Queue *queue) {
    while (!isQueueEmpty(queue)) {
        free(dequeue(queue));
    }
}
