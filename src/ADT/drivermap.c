#include <stdio.h>
#include "../src/ADT/map.h"

int main() {
    printf("=== Test Map===\n\n");
    
    Map m;
    printf("Test 1: Kondisi Map setelah inisialisasi\n");
    initMap(&m);
    if (map_isEmpty(&m)) {
        printf("Map Kosong\n");
    } else {
        printf("Map tidak kosong\n");
    }
    
    if (map_isFull(&m)) {
        printf("Map Penuh\n");
    } else {
        printf("Map tidak penuh\n");
    }
    printf("\n");
    printf("Test 2: Insert elemen\n");
    insertMap(&m, "ayam", 5);
    insertMap(&m, "sate", 10);
    insertMap(&m, "kucai", 3);
    insertMap(&m, "manisan", 7);
    printf("Map:\n");
    printMap(&m);
    printf("\n");

    printf("Test 3: Mencari elemen\n");
    printf("Cari indkes 'ayam': %d\n", searchMap(&m, "ayam"));
    printf("Cari indeks 'bakso' (tidak ada): %d\n", searchMap(&m, "bakso"));
    printf("\n");
    printf("Cari apakah sate ada di dalam map\n");
    if (inMap(&m, "sate")) {
        printf("'sate' ada di map\n");
    } else {
        printf("'sate' tidak ada di map\n");
    }
    printf("Cari apakah bakso ada di dalam map\n");
    if (inMap(&m, "bakso")) {
        printf("'bakso' ada di map\n");
    } else {
        printf("'bakso' tidak ada di map\n");
    }
    printf("\n");
    printf("Test 4: Get Value\n");
    printf("Value dari'kucai':%d\n", getValueMap(&m, "kucai"));
    printf("Value dari 'ayam: %d\n", getValueMap(&m, "ayam"));
    printf("\n");
    printf("Test 5: Update\n");
    printf("Sebelum update:\n");
    printMap(&m);
    updateMap(&m, "ayam", 15);
    printf("\nSetelah update 'ayam' menjadi 15:\n");
    printMap(&m);
    printf("\n");

    printf("Test 6: Delete\n");
    printf("Sebelum penghapusan:\n");
    printMap(&m);
    deleteFromMap(&m, "sate");
    printf("\nSetelah menghapus 'sate':\n");
    printMap(&m);
    printf("\n");

    printf("Test 7: Insert duplikat\n");
    printf("Coba menambahkan duplikat\n");
    insertMap(&m, "ayam", 20);
    printf("Setelah mencoba menambahkan 'ayam'dengan value 20:\n");
    printMap(&m);
    printf("\n");
    printf("update key yang tidak ada ('bakso'):\n");
    updateMap(&m, "bakso", 100);
    printMap(&m);

    printf("mencari value dari key yang tidak ada ('bakso'):\n");
    getValueMap(&m, "bakso");
    printf("\n");

    printf("Clear Map\n");
    deleteFromMap(&m, "ayam");
    deleteFromMap(&m, "kucai");
    deleteFromMap(&m, "manisan");

    printf("Kondisi setelah melakukan delete semua elemen:\n");
    printMap(&m);

    return 0;
}
