#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Queue q;
    int val;

    // Buat queue kosong
    printf("=== TESTER QUEUE ===\n");
    printf("Membuat Queue kosong...\n");
    CreateQueue(&q);

    // Validasi Queue Kosong
    printf("Apakah Queue kosong? %s\n", IsEmpty(q) ? "Ya" : "Tidak");

    // Tambahkan elemen ke queue
    printf("\nMenambahkan elemen: 1, 2, 3...\n");
    Enqueue(&q, 1);
    Enqueue(&q, 2);
    Enqueue(&q, 3);

    // Tampilkan isi queue
    printf("Isi Queue (dari head ke tail): ");
    displayQueue(q);

    // Validasi elemen dalam Queue
    printf("\nApakah elemen 2 ada di Queue? %s\n", isInQueue(q, 2) ? "Ya" : "Tidak");
    printf("Apakah elemen 5 ada di Queue? %s\n", isInQueue(q, 5) ? "Ya" : "Tidak");

    // Tambahkan elemen hingga Queue penuh
    printf("\nMenambahkan elemen hingga penuh...\n");
    for (int i = 4; i <= CAPACITY; i++) {
        Enqueue(&q, i);
    }

    printf("Apakah Queue penuh? %s\n", IsFull(q) ? "Ya" : "Tidak");

    // Coba menambahkan elemen pada Queue penuh
    printf("\nMenambahkan elemen ke Queue penuh...\n");
    Enqueue(&q, 101); // Harus gagal

    // Tampilkan isi Queue
    printf("\nIsi Queue setelah penambahan penuh: ");
    displayQueue(q);

    // Hapus beberapa elemen dari queue
    printf("\nMenghapus 3 elemen dari Queue...\n");
    for (int i = 0; i < 3; i++) {
        Dequeue(&q, &val);
        printf("Elemen yang dihapus: %d\n", val);
    }

    // Tampilkan isi Queue setelah penghapusan
    printf("\nIsi Queue setelah penghapusan: ");
    displayQueue(q);

    // Validasi Queue Kosong setelah penghapusan
    printf("\nApakah Queue kosong? %s\n", IsEmpty(q) ? "Ya" : "Tidak");

    return 0;
}
