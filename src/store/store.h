#ifndef STORE_H
#define STORE_H
#include "./../structs/item.h"

/// @brief Menampilkan hal yang ada dalam list item
/// @param item_list list item yang ada dalam state program
void store_list(DList *item_list);

/// @brief Me-request sebuah item (menambahkannya ke queue pada state program)
/// @param item_queue queue yang ada pada state program
/// @param nama nama item yang ingin ditambahkan
/// @return mengembalikan true jika item berhasil di-request
boolean store_req(Queue *item_queue, DList *item_store, char *nama);

/// @brief Memproses queue yang ada pada store
/// @param item_queue queue request
/// @param item_list list item yang dijual oleh store
void store_supply(Queue *item_queue, DList *item_list);

/// @brief Menghapus item pada store
/// @param store_items list item pada store
/// @param namabarang nama item yang ingin dihapus
/// @return mengembalikan true jika berhasil dihapus
boolean store_remove(DList *store_items, char *namabarang);
#endif
