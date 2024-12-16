#include "./../src/ADT/stack.h"
#include "stdlib.h"
#include "stdio.h"

int main(void){
    Stack test_stack;
    initStack(&test_stack);
    print_stack(&test_stack);

    Riwayat buku = newRiwayat("Introduction to Algorithms", 100);
    Riwayat baju = newRiwayat("Jaket HMIF", 200);
    // Test push
    stack_push(&test_stack,buku);
    stack_push(&test_stack,baju);
    print_stack(&test_stack);

    // Test top
    Riwayat top = stack_top(&test_stack);
    printf("Top:\n%s harga %d\n",top.nama_barang, top.harga);
    print_stack(&test_stack);

    // Test pop
    stack_pop(&test_stack,&buku);
    print_stack(&test_stack);

    return 0;
}