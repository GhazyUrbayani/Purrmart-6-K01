#include "item.h"
#include "./../ADT/listdinamis.h"

#include "./../ADT/mesinkata/mesinkata.h" 
#include <stdio.h>

/* Membuat Barang baru */
void CreateItem(Item *b, char name[], int price) {
    CopyString(b->name, name); // Menggunakan fungsi dari MesinKata
    b->price = price;
}

/* Mengecek apakah dua Barang sama berdasarkan nama */
boolean CompareItem(Item b1, Item b2) {
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
void DeleteItem(Item *b) {
    b->name[0] = '\0'; // Mengosongkan nama
    b->price = 0;      // Mengosongkan harga
}

/* 
    List Statis Item
 */
void is_initList(SList *list) {
    s_initList(list);
}
void is_addItem(SList *list, Item *item) {
    s_addItem(list, item, sizeof(Item));
}
void is_insertItem(SList *list, size_t index, Item *item) {
    s_insertItem(list,index,item,sizeof(Item));
}
void is_removeItem(SList *list, size_t index) {
    s_removeItem(list,index);
}
Item* is_getItem(SList *list, size_t index) {
    return s_getItem(list,index);
}
void is_setItem(SList *list, size_t index, Item *item) {
    s_setItem(list,index,item,sizeof(Item));
}
void is_clearList(SList *list) {
    s_clearList(list);
}

/* 
    List Dinamis Item
 */
DList* id_createList() {
    return d_createList();
}
void id_addItem(DList *list, Item *item) {
    d_addItem(list,item,sizeof(Item));
}
void id_insertItem(DList *list, size_t index, Item *item) {
    d_insertItem(list,index,item,sizeof(Item));
}
void id_removeItem(DList *list, size_t index) {
    d_removeItem(list,index);
}
Item* id_getItem(DList *list, size_t index) {
    d_getItem(list,index);
}
void id_setItem(DList *list, size_t index, Item *item) {
    d_setItem(list,index,item,sizeof(Item));
}
void id_clearList(DList *list) {
    d_clearList(list);
}
void id_freeList(DList *list) {
    d_freeList(list);
}

void ReadItem(DList *itemList) {
    Item item;
    ADVWORD();
    item.price = WordToInt(currentWord);
    IgnoreBlank();
    ADVSENTENCENL();
    CopyString(item.name, currentWord.TabWord);
    id_addItem(itemList, &item);
}
void WriteItems(DList *items, FILE *file) {
    fprintf(file, "%zu\n", items->size); // Write the number of items
    for (size_t i = 0; i < items->size; i++) {
        Item *item = (Item *)items->items[i]; // Cast to Item
        fprintf(file, "%d %s\n", item->price, item->name);
    }
}

/* 
    Queue Item
 */

void iinitQueue(Queue *queue) {
    initQueue(queue);
}
int iisQueueEmpty(Queue *queue) {
    return isQueueEmpty(queue);
}
int iisQueueFull(Queue *queue) {
    return isQueueFull(queue);
}
void ienqueue(Queue *queue, Item *item) {
    enqueue(queue,item,sizeof(Item));
}
Item* idequeue(Queue *queue) {
    dequeue(queue);
}
Item* ipeekQueue(Queue *queue) {
    peekQueue(queue);
}
void iclearQueue(Queue *queue) {
    clearQueue(queue);
}
