#ifndef LIST_STATIS_H
#define LIST_STATIS_H

#include <stdlib.h>

#define SLIST_CAPACITY 100 // Kapasitas maksimal list statis

typedef struct {
    void *items[SLIST_CAPACITY]; // Array elemen
    size_t itemSizes[SLIST_CAPACITY]; // Ukuran masing-masing elemen
    size_t size; // Jumlah elemen saat ini
} SList;

// Prototipe fungsi
void s_initList(SList *list);
void s_addItem(SList *list, void *item, size_t itemSize);
void s_insertItem(SList *list, size_t index, void *item, size_t itemSize);
void s_removeItem(SList *list, size_t index);
void* s_getItem(SList *list, size_t index);
void s_setItem(SList *list, size_t index, void *item, size_t itemSize);
void s_clearList(SList *list);

#endif
