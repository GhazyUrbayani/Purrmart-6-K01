# include <stdio.h>
# include "../ADT/linkedList.h"
# include "../ADT/mesinkata/mesinkata.h"
# include "../ADT/listdinamis.h"

void wishlistadd (LinkedList *wishlist, DList list_barang){
    printf("Masukkan nama barang yang ingin ditambahkan ke wishlist: ");
    Word input;
    STARTWORDINPUT();
    input = currentWord;
    for (int i = 0; i<list_barang.size; i++){
        if (STRING(currentWord) == list_barang.items[i]){
            printf("Barang tidak ada di toko\n");
            return;
        }
    }
    if ll_isEmpty(wishlist){
        ll_insert(wishlist, STRING(input));
        printf("%s berhasil ditambahkan ke wishlist\n", input);
    }else{
        linkednode* temp = ll_search(wishlist, STRING(input));
        if (temp == NULL){
            ll_insert(wishlist, STRING(input));
            printf("%s berhasil ditambahkan ke wishlist\n", STRING(input));
        }else{
            printf("Barang sudah ada di wishlist\n");
        }
    }
    
}