#ifndef CART_H
#define CART_H

#include "./../structs/item.h"
#include "./../ADT/map.h"
#include "./../ADT/stack.h"


void cartAdd(Map* keranjang_user, char* namabarang, int kuantitas, DList* store_items);

void cartRemove(Map* keranjang_user, char* namabarang, int kuantitas);

void cartShow(Map* keranjang_user, DList* item_store);

void cartPay(Map* keranjang_user, Stack* riwayat_user, int* uang_user, DList* store_items);

int lokasi_max_total(Map* keranjang_belanja, DList* toko_barang);
#endif