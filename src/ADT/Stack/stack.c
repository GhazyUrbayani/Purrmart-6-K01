#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
//Ideal untuk menyimpan riwayat data (LIFO), seperti riwayat tebakan pada game

/* Membuat stack kosong */
void CreateStack(Stack *s) {
    // Inisialisasi top sebagai -1 (kosong)
    s->top = -1;
}

/* Mengecek apakah stack kosong */
bool IsEmpty(Stack s) {
    return s.top == -1; // true jika top == -1
}

/* Mengecek apakah stack penuh */
bool IsFull(Stack s) {
    return s.top == CAPACITY - 1; // true jika top mencapai kapasitas
}

/* Menambahkan elemen ke atas stack */
void Push(Stack *s, ElType val) {
    if (!IsFull(*s)) {
        // Tambahkan elemen di indeks top+1
        s->buffer[++s->top] = val;
    }
}

/* Menghapus elemen dari atas stack */
void Pop(Stack *s, ElType *val) {
    if (!IsEmpty(*s)) {
        // Ambil elemen pada top dan kurangi top
        *val = s->buffer[s->top--];
    }
}