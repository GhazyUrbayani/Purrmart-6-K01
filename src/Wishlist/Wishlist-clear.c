# include <stdio.h>
# include <stdlib.h>
# include "../ADT/linkedList.h"
# include "Wishlist-clear.h"

void wishlistclear (LinkedList  *wishlist){
    if (ll_isEmpty (wishlist)){
        printf("Wishlist kosong\n");
        return;
    }
    ll_clear(wishlist);
    printf("Wishlist berhasil dihapus\n");
}