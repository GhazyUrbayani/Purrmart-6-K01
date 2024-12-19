<<<<<<< HEAD
#include "stack.h"

void CreateStack(Stack *S)
{
    Top(*S) = Nil;
}

boolean IsStackEmpty(Stack S)
{
    return Top(S) == Nil;
}

boolean IsStackFull(Stack S)
{
    return Top(S) == MaxEl - 1;
}

void Push(Stack *S, infotypeStack X, boolean *succeed)
{
    if (IsStackEmpty(*S))
    {
        Top(*S) += 1;
        InfoTop(*S) = X;
        (*succeed) = true;
    }
    else
    {
        if (X < InfoTop(*S))
        {
            Top(*S) += 1;
            InfoTop(*S) = X;
            (*succeed) = true;
        }
        else
        {
            (*succeed) = false;
        }
    }
}

void Pop(Stack *S, infotypeStack *X, boolean *succeed)
{
    if (!IsStackEmpty(*S))
    {
        (*X) = InfoTop(*S);
        Top(*S) -= 1;
        (*succeed) = true;
    }
    else
    {
        (*succeed) = false;
    }
=======
#include "stack.h"
#include <stdio.h>
#include "utils.h"

void initStack(Stack* s) {
    s->top = -1;
}

boolean stack_isEmpty(Stack* s) {
    return (s->top == -1);
}

boolean stack_isFull(Stack* s) {
    return (s->top == MAXSTACK - 1);
}

void stack_push(Stack* s, Riwayat r) {
    if (stack_isFull(s)) return;
    s->top++;
    s->elemen[s->top].nama_barang = str_copy(r.nama_barang);
    s->elemen[s->top].harga = r.harga;
}

void stack_pop(Stack* s, Riwayat* r) {
    if (stack_isEmpty(s)) return;
    *r = s->elemen[s->top];
    s->top--;
}

Riwayat stack_top(Stack *s) {
    if (stack_isEmpty(s)) fprintf(stderr,"Stack kosong");
    return s->elemen[s->top];
}

void print_stack(Stack* s) {
    print_stackToFile(s,stdout);
}

void print_stackToFile(Stack* s, FILE* stream) {
    if (stack_isEmpty(s)) return;
    for (int i = 0; i <= s->top; i++) {
        Riwayat current = s->elemen[i];
        fprintf(stream,"%d %s\n", current.harga, current.nama_barang);
    }
}

Riwayat newRiwayat(char* nama, int harga) {
    Riwayat new;
    new.nama_barang = str_copy(nama);
    new.harga = harga;
    return new;
>>>>>>> feature/Wishlist
}