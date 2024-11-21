#ifndef LIST_DINAMIS_H
#define LIST_DINAMIS_H

#include <stdlib.h>

#define DLIST_DEF_CAPACITY 10 // Kapasitas awal list dinamis

typedef struct {
    void **items;   // Pointer array untuk menyimpan elemen
    size_t capacity; // Kapasitas list
    size_t size;     // Jumlah elemen dalam list
} DList;

// Prototipe fungsi
DList* d_createList();
void d_addItem(DList *list, void *item, size_t itemSize);
void d_insertItem(DList *list, size_t index, void *item, size_t itemSize);
void d_removeItem(DList *list, size_t index);
void* d_getItem(DList *list, size_t index);
void d_setItem(DList *list, size_t index, void *item, size_t itemSize);
void d_clearList(DList *list);
void d_freeList(DList *list);

#endif
