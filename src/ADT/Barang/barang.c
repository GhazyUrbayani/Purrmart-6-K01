#include "barang.h"
#include "./../Mesin Kata/mesinkata.h" 

/* Membuat Barang baru */
void CreateBarang(Barang *b, char name[], int price) {
    CopyString(b->name, name); // Menggunakan fungsi dari MesinKata
    b->price = price;
}

/* Mengecek apakah dua Barang sama berdasarkan nama */
boolean IsSameBarang(Barang b1, Barang b2) {
    int i = 0;
    while (b1.name[i] != '\0' && b2.name[i] != '\0') {
        if (b1.name[i] != b2.name[i]) {
            return false;
        }
        i++;
    }
    return b1.name[i] == '\0' && b2.name[i] == '\0';
}

/* Menghapus data Barang */
void DeleteBarang(Barang *b) {
    b->name[0] = '\0'; // Mengosongkan nama
    b->price = 0;      // Mengosongkan harga
}
