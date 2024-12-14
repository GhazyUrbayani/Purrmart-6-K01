#include "stack.h"
#include <stdio.h>

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
    s->elemen[s->top] = r;
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