#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
//Ideal untuk menyimpan riwayat data (LIFO), seperti riwayat tebakan pada game

/* Membuat Stack kosong */
void CreateStack(Stack *s) {
    s->top = -1;
    // Reminder: Top diinisialisasi ke -1 untuk menunjukkan Stack kosong
}

/* Mengecek apakah Stack kosong */
bool IsEmpty(Stack s) {
    return s.top == -1; // true jika top == -1
    // Reminder: Top = -1 berarti tidak ada elemen di Stack
}

/* Mengecek apakah Stack penuh */
bool IsFull(Stack s) {
    // Tambahkan elemen di indeks top+1
    return s.top == CAPACITY - 1; // true jika top mencapai kapasitas
    // Reminder: Top = CAPACITY - 1 berarti Stack penuh
}

/* Menambahkan elemen ke atas Stack */
void Push(Stack *s, ElType val) {
    if (!IsFull(*s)) {
        s->buffer[++s->top] = val;
        // Reminder: Top diperbarui, elemen ditambahkan ke posisi top
    }
}

/* Menghapus elemen dari atas Stack */
void Pop(Stack *s, ElType *val) {
    if (!IsEmpty(*s)) {
        // Ambil elemen pada top dan kurangi top
        *val = s->buffer[s->top--];
        // Reminder: Elemen di top dihapus, top diperbarui
    }
}
