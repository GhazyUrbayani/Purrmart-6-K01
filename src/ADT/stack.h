#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include "boolean.h"
#define MAXSTACK 100

typedef struct Riwayat {
    char* nama_barang;
    int harga;
} Riwayat;

typedef struct Stack {
    Riwayat elemen[MAXSTACK];
    int top;
} Stack;

void initStack(Stack* s);

boolean stack_isEmpty(Stack* s);

boolean stack_isFull(Stack* s);

void stack_push(Stack* s, Riwayat r);

void stack_pop(Stack* s, Riwayat* r);

Riwayat stack_top(Stack* s);

void print_stack(Stack* s);

void print_stackToFile(Stack* s, FILE* stream);

Riwayat newRiwayat(char* nama, int harga);

#endif