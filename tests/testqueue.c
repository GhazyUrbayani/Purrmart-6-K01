#include "./../src/structs/item.h"

int main(void) {
    printf("\n=== *** Test Queue *** ===\n");
    
    printf("\nTC 01 : Buat queue barang\n");
    Queue queue_barang; iinitQueue(&queue_barang);
    printf("Terbentuk queue barang dengan ukuran %d dan indeks front %d dan rear %d\n",queue_barang.size,queue_barang.front,queue_barang.rear);


    printf("\nTC 02 : Enqueue barang\n");
    Item kocak; CreateItem(&kocak,"Nama Barang",50);
    ienqueue(&queue_barang,&kocak);
    printf("Queue barang. Front = %d. Rear = %d. Size = %d\n",queue_barang.front,queue_barang.rear,queue_barang.size);
    printf("Enqueue sekali lagi.\n");
    ienqueue(&queue_barang,&kocak);
    printf("Queue barang. Front = %d. Rear = %d. Size = %d\n",queue_barang.front,queue_barang.rear,queue_barang.size);

    printf("\nTC 03: Dequeue Barang\n");
    Item *dinda = idequeue(&queue_barang);
    printf("Item '%s' dengan harga %d keluar dari queue\n", dinda->name, dinda->price);
    printf("Queue barang. Front = %d. Rear = %d. Size = %d\n",queue_barang.front,queue_barang.rear,queue_barang.size);

    printf("\nTC 04: Peek Head Queue\n");
    Item *laptop = ipeekQueue(&queue_barang);
    printf("Item '%s' dengan harga %d diintip dari queue\n", laptop->name, laptop->price);
    printf("Queue barang. Front = %d. Rear = %d. Size = %d\n",queue_barang.front,queue_barang.rear,queue_barang.size);

    printf("\nTC 05: Clear queue\n");
    iclearQueue(&queue_barang);
    printf("Queue barang. Front = %d. Rear = %d. Size = %d\n",queue_barang.front,queue_barang.rear,queue_barang.size);
}