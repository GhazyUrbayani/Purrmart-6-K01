#include "store.h"
#include "./../ADT/utils.h"

void store_list(DList *item_list) {
    if (item_list->size==0) {
        printf("Toko kosong.\n");
    } else {
        printf("List barang yang ada di toko:\n");
        for (int i = 0; i < item_list->size; i++) {
            Item* current_item = id_getItem(item_list,i);
            printf("- %s - Harga: %d\n", current_item->name, current_item->price);
        }
    }
}

boolean store_req(Queue *item_queue, DList *item_store, char *nama) {
    // Uji Queue
    int queue_count = item_queue->size;
    for (int i = 0; i < queue_count; i++) {
        Item *item = idequeue(item_queue);
        ienqueue(item_queue,item);
        if (str_compare(item->name,nama)) {
            return 0;
        }
    }
    // Uji store
    for (int i = 0; i <item_store->size;i++) {
        Item *item = id_getItem(item_store,i);
        if (str_compare(nama,item->name)) {
            return 0;
        }
    }
    Item req; CreateItem(&req,nama,0);
    ienqueue(item_queue,&req);
    return 1;
}

void store_supply(Queue *item_queue, DList *item_list) {
    if (item_queue->size == 0) {
        printf("Request kosong.\n");
        return;
    }
    Item *peeked = ipeekQueue(item_queue);
    char *item_name = peeked->name;
    printf("Apakah kamu ingin menambahkan barang %s?: ", item_name);
    printf("TERIMA/TUNDA/TOLAK\n");
    STARTWORDINPUT();
    if (str_compare(STRING(currentWord),"TERIMA")) {
        printf("Harga barang: ");
        STARTWORDINPUT();
        int harga = WordToInt(currentWord);
        peeked->price = harga;
        id_addItem(item_list,peeked);
        dequeue(item_queue);
        printf("%s dengan harga %d telah ditambahkan ke toko.\n",item_name,harga);
    } else if (str_compare(STRING(currentWord),"TUNDA")) {
        Item *dequeued = idequeue(item_queue);
        ienqueue(item_queue,dequeued);
        printf("%s dikembalikan ke antrian.\n",item_name);
    } else if (str_compare(STRING(currentWord),"TOLAK")) {
        printf("%s dihapus dari antrian.\n",item_name);
        idequeue(item_queue);
    }
}

boolean store_remove(DList *store_items, char *namabarang) {
    for (int i = 0; i < store_items->size; i++) {
        Item *barang = id_getItem(store_items,i);
        if (str_compare(barang->name,namabarang)) {
            id_removeItem(store_items,i);
            return 1;
        }
    }
    return 0;
}