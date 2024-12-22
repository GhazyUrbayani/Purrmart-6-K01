#ifndef CART_H
#define CART_H

#include "set.h"
#include "utils.h"
#include "boolean.h"
#include <stdio.h>

#define MAX_NAME_LEN 100

typedef struct {
    char names[MaxEl][MAX_NAME_LEN];  // Nama barang
    int quantities[MaxEl];            // Kuantitas barang
} Cart;

void CartAdd(Set *S, Cart *C, char *item, int qty);
/* Menambahkan barang (item) dan kuantitas (qty) ke keranjang. */

void CartRemove(Set *S, Cart *C, char *item, int qty);
/* Mengurangi barang (item) sejumlah (qty) dari keranjang. */

#endif
