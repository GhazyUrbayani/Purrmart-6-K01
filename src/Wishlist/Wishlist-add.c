# include <stdio.h>
# include "../ADT/linkedlist.h"
# include "../ADT/mesinkata/mesinkata.h"
# include "../ADT/listdinamis.h"
#include "./../ADT/utils.h"
#include "./../structs/item.h"

void wishlistadd (LinkedList *wishlist, DList list_barang){
    printf("Masukkan nama barang yang ingin ditambahkan ke wishlist: ");
    Word input;
    STARTWORDINPUT();
    input = currentWord;
    if (id_search(&list_barang,STRING(currentWord)) != -1) {
        linkednode* itemloc = ll_search(wishlist,STRING(currentWord));
        if (itemloc == NULL) {
            ll_insert(wishlist, STRING(input));
            printf("%s berhasil ditambahkan ke wishlist\n", STRING(input));
        } else {
            printf("Barang sudah ada di wishlist\n");
        }
    } else {
        printf("Barang tidak ada di store!\n");
    }
}