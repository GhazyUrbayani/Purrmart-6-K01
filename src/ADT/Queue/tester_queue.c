#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
//Queue: Memastikan operasi FIFO (enqueue dan dequeue) berjalan sesuai harapan

int main() {
    Queue q;
    int val;

    // Buat queue kosong
    printf("Membuat Queue kosong...\n");
    CreateQueue(&q);

    // Tambahkan elemen ke queue
    printf("Menambahkan elemen: 1, 2, 3...\n");
    Enqueue(&q, 1);
    Enqueue(&q, 2);
    Enqueue(&q, 3);

    // Tampilkan isi queue
    printf("Isi Queue (dari head ke tail): ");
    int i = q.head;
    while (i != q.tail) {
        printf("%d ", q.buffer[i]);
        i = (i + 1) % CAPACITY;
    }
    printf("%d\n", q.buffer[q.tail]);

    // Hapus elemen dari queue
    printf("Menghapus elemen pertama...\n");
    Dequeue(&q, &val);
    printf("Elemen yang dihapus: %d\n", val);

    // Tampilkan isi queue setelah penghapusan
    printf("Isi Queue setelah penghapusan: ");
    i = q.head;
    while (i != q.tail) {
        printf("%d ", q.buffer[i]);
        i = (i + 1) % CAPACITY;
    }
    if (!IsEmpty(q)) printf("%d\n", q.buffer[q.tail]);

    return 0;
}
