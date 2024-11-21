#include <stdio.h>
#include <stdlib.h>
#include "liststatis.h"
#include "utils.h"

void s_initList(SList *list) {
    list->size = 0;
}

void s_addItem(SList *list, void *item, size_t itemSize) {
    if (list->size >= SLIST_CAPACITY) {
        printf("List penuh.\n");
        return;
    }
    list->items[list->size] = alokasi_salin(item, itemSize);
    list->itemSizes[list->size] = itemSize;
    list->size++;
}

void s_insertItem(SList *list, size_t index, void *item, size_t itemSize) {
    if (list->size >= SLIST_CAPACITY) {
        printf("List penuh.\n");
        return;
    }
    if (index > list->size) {
        printf("Indeks di luar ukuran.\n");
        return;
    }
    for (size_t i = list->size; i > index; --i) {
        list->items[i] = list->items[i - 1];
        list->itemSizes[i] = list->itemSizes[i - 1];
    }
    list->items[index] = alokasi_salin(item, itemSize);
    list->itemSizes[index] = itemSize;
    list->size++;
}

void s_removeItem(SList *list, size_t index) {
    if (index >= list->size) {
        printf("Indeks di luar ukuran.\n");
        return;
    }
    free(list->items[index]);
    for (size_t i = index; i < list->size - 1; ++i) {
        list->items[i] = list->items[i + 1];
        list->itemSizes[i] = list->itemSizes[i + 1];
    }
    list->size--;
}

void* s_getItem(SList *list, size_t index) {
    if (index >= list->size) {
        printf("Indeks di luar ukuran.\n");
        return NULL;
    }
    return list->items[index];
}

void s_setItem(SList *list, size_t index, void *item, size_t itemSize) {
    if (index >= list->size) {
        printf("Indeks di luar ukuran.\n");
        return;
    }
    free(list->items[index]);
    list->items[index] = alokasi_salin(item, itemSize);
    list->itemSizes[index] = itemSize;
}

void s_clearList(SList *list) {
    for (size_t i = 0; i < list->size; i++) {
        free(list->items[i]);
    }
    list->size = 0;
}
