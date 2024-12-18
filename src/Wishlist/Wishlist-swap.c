# include <stdio.h>
# include <stdlib.h>
# include "../ADT/linkedList.h"
# include "Wishlist-swap.h"

void wishlistswap (LinkedList* wishlist, int idx1, int idx2){
    if (ll_isEmpty (wishlist)){
        printf("Wishlist Kosong, gagal menukar posisi pada wishlist\n");
        return;
    }
    if (idx1 == idx2){
        printf("Posisi sama, gagal menukar posisi pada wishlist\n");
        return;
    }
    if (idx1 > ll_count(wishlist) || idx2 > ll_count(wishlist)||idx1 < 0 || idx2 < 0){
        printf("Indeks tidak valid, gagal menukar posisi pada wishlist\n");
        return;
    }
    linkednode* curridx1 = wishlist->head;
    for (int i = 0; i < idx1; i++){
        curridx1 = curridx1->next;
    }
    linkednode* curridx2 = wishlist->head;
    for (int i = 0; i < idx2; i++){
        curridx2 = curridx2->next;
    }
    linkednode* nextidx1 = curridx1->next;
    linkednode* previdx1 = curridx1->prev;
    linkednode* nextidx2 = curridx2->next;
    linkednode* previdx2 = curridx2->prev;
    if (nextidx1 == curridx2||nextidx2 == curridx1){
        if (nextidx1 == curridx2){
            curridx1->next = curridx2->next;
            curridx1->prev = curridx2;
            curridx2->next = curridx1;
            curridx2->prev = previdx1;
            if (previdx1 != NULL){
                previdx1->next = curridx2;
            } else {
                wishlist->head = curridx2;
            }
            if (nextidx2 != NULL){
                nextidx2->prev = curridx1;
            }
        }else{
            curridx2->next = nextidx1;
            curridx2->prev = curridx1;
            curridx1->next = curridx2;
            curridx1->prev = previdx2;
        if (previdx2 != NULL) {
            previdx2->next = curridx1;
            } else {
            wishlist->head = curridx1;
            }
            if (nextidx1 != NULL) {
                nextidx1->prev = curridx2;
            }
        }
    }else{
        curridx1->next = nextidx2;
        curridx1->prev = previdx2;
        curridx2->next = nextidx1;
        curridx2->prev = previdx1;
        if (previdx1 != NULL){
            previdx1->next = curridx2;
        } else {
            wishlist->head = curridx2;
        }
        if (nextidx1 != NULL){
            nextidx1->prev = curridx2;
        }
        if (previdx2 != NULL){
            previdx2->next = curridx1;
        } else {
            wishlist->head = curridx1;
        }
        if (nextidx2 != NULL){
            nextidx2->prev = curridx1;
        }
    }
    printf("Posisi wishlist berhasil di tukar\n");
}
