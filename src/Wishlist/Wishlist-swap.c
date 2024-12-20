#include <stdio.h>
#include <stdlib.h>
#include "../ADT/linkedList.h"
#include "Wishlist-swap.h"

void wishlistswap(LinkedList* wishlist, int idx1, int idx2) {
    if (idx1 == idx2) {
        printf("Index sama!\n");
        return;
    }

    // Get the nodes at the specified indices
    linkednode* node1 = ll_get_node_at(wishlist, idx1);
    linkednode* node2 = ll_get_node_at(wishlist, idx2);

    if (!node1 || !node2) {
        printf("Index tidak valid! (Pastikan mulai dari 1 dan sesuai jumlah wishlist)\n");
        return;
    }

    // Handle head and tail updates
    if (wishlist->head == node1) {
        wishlist->head = node2;
    } else if (wishlist->head == node2) {
        wishlist->head = node1;
    }

    // Handle swapping links for `prev`
    if (node1->prev) {
        node1->prev->next = node2;
    }
    if (node2->prev) {
        node2->prev->next = node1;
    }

    // Handle swapping links for `next`
    if (node1->next) {
        node1->next->prev = node2;
    }
    if (node2->next) {
        node2->next->prev = node1;
    }

    // Swap `prev` pointers
    linkednode* temp_prev = node1->prev;
    node1->prev = node2->prev;
    node2->prev = temp_prev;

    // Swap `next` pointers
    linkednode* temp_next = node1->next;
    node1->next = node2->next;
    node2->next = temp_next;

    printf("Menukar %s (indeks %d) dengan %s (indeks %d) berhasil!\n",
           node1->key, idx1, node2->key, idx2);
}
