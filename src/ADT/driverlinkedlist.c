#include <stdio.h>
#include "../src/ADT/linkedlist.h"
#include <stdlib.h>

// driver linkedlist
int main() {
    LinkedList list;
    printf("=== TEST LINKEDLIST ===\n\n");

    printf("Test 1: inisialisasi list\n");
    ll_initList(&list);
    if (ll_isEmpty(&list)) {
        printf("List Kosong\n");
    }
    printf("List count: %d\n\n", ll_count(&list));
    
    printf("Test 2: Memasukkan elemen\n");
    printf("Insert kata: 'hi', 'aku', 'menyerah', 'hehe'\n");
    ll_insert(&list, "hi");
    ll_insert(&list, "aku");
    ll_insert(&list, "menyerah");
    ll_insert(&list, "hehe");
    printf("List:\n");
    ll_printList(&list);
    printf("List count: %d\n\n", ll_count(&list));
    
    printf("Test 3: Mencari elemen dalam list\n");
    if (ll_search(&list, "aku") != NULL) {
        printf("Element 'aku' ditemukan\n");
    }
    if (ll_search(&list, "tidak ada") == NULL) {
        printf("Element 'tidak ada' tidak ditemukan\n");
    }
    printf("\n");
    
    printf("Test 4: Menghapus elemen\n");
    printf("Delete 'hehe'\n");
    ll_delete(&list, "hehe");
    printf("List:\n");
    ll_printList(&list);
    printf("List count: %d\n\n", ll_count(&list));
    
    printf("Delete 'hi'\n");
    ll_delete(&list, "hi");
    printf("List:\n");
    ll_printList(&list);
    
    printf("Delete 'menyerah'\n");
    ll_delete(&list, "menyerah");
    printf("List:\n");
    ll_printList(&list);
    printf("List count: %d\n\n", ll_count(&list));
    
    printf("Test 6: Free List\n");
    ll_freeList(&list);
    if (ll_isEmpty(&list)) {
        printf("List Kosong\n");
    }
    printf("List count: %d\n\n", ll_count(&list));
    
    printf("Test 7: Memasukkan elemen kembali\n");
    printf("Insert 'baru'\n");
    ll_insert(&list, "baru");
    printf("List:\n");
    ll_printList(&list);
    printf("List count: %d\n\n", ll_count(&list));
    
    ll_freeList(&list);
    printf("=== BYE WORLD ===\n");
    
    return 0;
}
