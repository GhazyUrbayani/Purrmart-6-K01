#ifndef WISHLIST_REMOVE_H
#define WISHLIST_REMOVE_H

#include "./../ADT/linkedlist.h"

/**
 * @brief Menghapus barang dari wishlist berdasarkan indeks.
 * @param wishlist Pointer ke LinkedList yang merepresentasikan wishlist.
 * @param index Posisi barang dalam wishlist yang akan dihapus.
 */
void wishlist_remove_index(LinkedList* wishlist, int index);

/**
 * @brief Menghapus barang dari wishlist berdasarkan nama.
 * @param wishlist Pointer ke LinkedList yang merepresentasikan wishlist.
 * @param name Nama barang yang akan dihapus dari wishlist.
 */
void wishlist_remove_name(LinkedList* wishlist, char* name);

#endif
