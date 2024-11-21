#ifndef START_H
#define START_H

#include "./../ADT/boolean.h"
#include "./../ADT/mesinkata/mesinkata.h"
#include "./../structs/item.h"
#include "./../structs/user.h"
#include "./../ADT/utils.h"

//Command START, read file default(config) dan memasukkan nilainya ke variable
void STARTPROGRAM(SList *users, DList **items, char *filename);

#endif