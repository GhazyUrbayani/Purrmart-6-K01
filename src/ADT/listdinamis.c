#include <stdio.h>
#include <stdlib.h>
#include "listdinamis.h"
#include "utils.h"

DList* d_createList() {
    DList *list = (DList*)malloc(sizeof(DList));
    if (!list) {
        perror("Alokasi memori untuk dynamic list (DList) gagal.\n");
    }
    list->items = (void**)malloc(DLIST_DEF_CAPACITY * sizeof(void*));
    if (!list->items) {
        perror("Alokasi memori untuk dynamic list (elemen DList) gagal.\n");
        free(list);
        exit(EXIT_FAILURE);
    }
    list->capacity = DLIST_DEF_CAPACITY;
    list->size = 0;
    return list;
}

// Resize the list
void d_resizeList(DList *list) {
    list->capacity *= 2;
    list->items = (void**)realloc(list->items, list->capacity * sizeof(void*));
    if (!list->items) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
}

// Add an item to the list
void d_addItem(DList *list, void *item, size_t itemSize) {
    if (list->size == list->capacity) {
        d_resizeList(list);
    }
    list->items[list->size++] = alokasi_salin(item, itemSize);
}

// Insert an item at a specific index
void d_insertItem(DList *list, size_t index, void *item, size_t itemSize) {
    if (index > list->size) {
        printf("Indeks di luar ukuran DList.\n");
        return;
    }
    if (list->size == list->capacity) {
        d_resizeList(list);
    }
    for (size_t i = list->size; i > index; --i) {
        list->items[i] = list->items[i - 1];
    }
    list->items[index] = alokasi_salin(item, itemSize);
    list->size++;
}

// Remove an item at a specific index
void d_removeItem(DList *list, size_t index) {
    if (index >= list->size) {
        printf("Indeks di luar ukuran DList.\n");
        return;
    }
    free(list->items[index]);
    for (size_t i = index; i < list->size - 1; ++i) {
        list->items[i] = list->items[i + 1];
    }
    list->size--;
}

// Get an item
void* d_getItem(DList *list, size_t index) {
    if (index >= list->size) {
        printf("Indeks di luar ukuran DList.\n");
        return NULL;
    }
    return list->items[index];
}

// Set (replace) an item
void d_setItem(DList *list, size_t index, void *item, size_t itemSize) {
    if (index >= list->size) {
        printf("Indeks di luar ukuran DList.\n");
        return;
    }
    free(list->items[index]);
    list->items[index] = alokasi_salin(item, itemSize);
}

// Clear all items in the list
void d_clearList(DList *list) {
    for (size_t i = 0; i < list->size; i++) {
        free(list->items[i]);
    }
    list->size = 0;
}

// Free the entire list
void d_freeList(DList *list) {
    d_clearList(list);
    free(list->items);
    free(list);
}
