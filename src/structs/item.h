#ifndef ITEM_H
#define ITEM_H

#include "./../ADT/boolean.h"
#include "./../ADT/mesinkata/mesinkata.h"
#include "./../ADT/liststatis.h" 
#include "./../ADT/listdinamis.h"
#include "./../ADT/queue.h"

#define MAX_LEN 100

typedef struct {
    char name[MAX_LEN];
    int price;
} Item;

/* *** Konstruktor *** */
/**
 * Membuat Item baru dengan atribut yang diberikan.
 * IS: Item belum terinisialisasi.
 * FS: Item terinisialisasi dengan nama dan harga.
 */
void CreateItem(Item *b, char name[], int price);

/* *** Fungsi dan Operasi *** */
/**
 * Mengecek apakah dua Item sama berdasarkan nama.
 * IS: Kedua Item valid.
 * FS: Tidak ada perubahan.
 * Return: true jika nama sama, false jika tidak.
 */
boolean CompareItem(Item b1, Item b2);

/**
 * Menghapus data Item dengan mengosongkan atribut-atributnya.
 * IS: Item valid dan terinisialisasi.
 * FS: Atribut Item di-set menjadi kosong atau default.
 */
void DeleteItem(Item *b);

/* 
    List Statis Item
 */

void is_initList(SList *list);
void is_addItem(SList *list, Item *item);
void is_insertItem(SList *list, size_t index, Item *item);
void is_removeItem(SList *list, size_t index);
Item* is_getItem(SList *list, size_t index);
void is_setItem(SList *list, size_t index, Item *item);
void is_clearList(SList *list);

/* 
    List Dinamis Item
 */

DList* id_createList();
void id_addItem(DList *list, Item *item);
void id_insertItem(DList *list, size_t index, Item *item);
void id_removeItem(DList *list, size_t index);
Item* id_getItem(DList *list, size_t index);
void id_setItem(DList *list, size_t index, Item *item);
void id_clearList(DList *list);
void id_freeList(DList *list);

int id_search(DList *list, char* namabarang);
Item* id_getItembyName(DList* list, char* namabarang);

void ReadItem(DList *itemList);
void WriteItems(DList *items, FILE *file);

/* 
    Queue Item
 */

void iinitQueue(Queue *queue);
int iisQueueEmpty(Queue *queue);
int iisQueueFull(Queue *queue);
void ienqueue(Queue *queue, Item *item);
Item* idequeue(Queue *queue);
Item* ipeekQueue(Queue *queue);
void iclearQueue(Queue *queue);

#endif
