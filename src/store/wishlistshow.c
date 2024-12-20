#include "wishlistshow.h"

void wishlistshow(LinkedList* wishlist) {
    if (wishlist->head == NULL) {
        printf("Wishlist kosong!\n");
    } else {
        int count = 1;
        linkednode* cursor = wishlist->head;
        printf("Berikut adalah isi wishlist-mu:\n");
        while (cursor != NULL) {
            printf("%d. %s\n", count++, cursor->key);
            cursor = cursor->next;
        }
    }
}