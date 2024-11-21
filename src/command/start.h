#ifndef START_H
#define START_H

#include "../ADT/boolean.h"
#include "../ADT/Mesin Karakter/mesinkarakter.h"
#include "../ADT/Mesin Kata/mesinkata.h"
#include "../ADT/ListDin/listdinstring.h"
#include "../ADT/List Statis/liststatuser.h"
#include "../ADT/User/user.h"
#include "../ADT/Barang/barang.h"

//Command START, read file default(config) dan memasukkan nilainya ke variable
void STARTPROGRAM(ListUser *users, ListBarang *items, char *filename);

#endif