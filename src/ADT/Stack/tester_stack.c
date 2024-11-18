#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
//Stack: Memastikan operasi LIFO (push dan pop) bekerja seperti yang diinginkan

int main() {
    Stack s;
    int val;

    // Buat stack kosong
    printf("Membuat Stack kosong...\n");
    CreateStack(&s);

    // Tambahkan elemen ke stack
    printf("Menambahkan elemen: 100, 200, 300...\n");
    Push(&s, 100);
    Push(&s, 200);
    Push(&s, 300);

    // Tampilkan isi stack (dari top ke bottom)
    printf("Isi Stack: ");
    for (int i = s.top; i >= 0; i--) {
        printf("%d ", s.buffer[i]);
    }
    printf("\n");

    // Hapus elemen dari stack
    printf("Menghapus elemen dari atas stack...\n");
    Pop(&s, &val);
    printf("Elemen yang dihapus: %d\n", val);

    // Tampilkan isi stack setelah penghapusan
    printf("Isi Stack setelah penghapusan: ");
    for (int i = s.top; i >= 0; i--) {
        printf("%d ", s.buffer[i]);
    }
    printf("\n");

    return 0;
}
